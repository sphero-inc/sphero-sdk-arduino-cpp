////////////////////////////////////////////////////////////////////////////////
//!
//! @addtogroup       api
//! @{
//!
//! @file             sphero_api.cpp
//!
//! @author           Julie Tan
//!
//! @date             7/9/2019
//!
//! @brief            Initalize the Sphero API system
//!
//! @details
//!
//! @copyright        2010-2019. Sphero Inc. (http://www.sphero.com)
//!                   All Rights Reserved
//!
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////

#include "Arduino.h"
#include "sphero_api.h"


///////////////////////////////////////////////////////////////////////////////
//  Private Types
///////////////////////////////////////////////////////////////////////////////

// Max API parser buffer size
#define MAX_API_PARSER_DATA_COUNT           (64)

// Max API response buffer size
#define MAX_API_RESPONSE_DATA_COUNT         (64)

// Max UART RX buffer
#define MAX_UART_RX_BUFFER_COUNT            (32)

typedef enum
{
    ARDUINO_API_PORT_UART     = 0x1,
} arduinoApiPort_t;

typedef struct
{
    //! Arduino internal nodes
    struct
    {
        apiAddress_t arduinoProcessor;
    } nodes;

    //! Arduino ports
    struct
    {
        apiAddress_t arduinoUartPeripheral;
    } ports;

    //! Some useful external node addresses
    struct
    {
        apiAddress_t nordicProcessor;
        apiAddress_t stProcessor;
    } externalNodes;

} arduinoApiAddresses_t;

///////////////////////////////////////////////////////////////////////////////
//  Private Function Prototypes
///////////////////////////////////////////////////////////////////////////////

static void sendBytesToUart(const ioChannel_t *channel, const uint8_t *data, size_t count);

///////////////////////////////////////////////////////////////////////////////
//  Private Data
///////////////////////////////////////////////////////////////////////////////
// Expansion of the parser cause an error because all the struct must be in order. To make it easier, let just do it here
static apiChannelParser_t uartChannelApiParser = INIT_API_CHANNEL_PARSER(API_PROTOCOL_V2, MAX_API_PARSER_DATA_COUNT);

// IO channel for UART
static ioChannel_t uartChannel;

// buffer for the api response data
static uint8_t apiResponseDataBuffer[MAX_API_RESPONSE_DATA_COUNT] = {0};

// Aruduino api address table with external nodes to talk to RVR
static arduinoApiAddresses_t arduinoApiAddresses =
{
    .nodes =
    {
      .arduinoProcessor = { .port = INTERNAL_PORT_ID, .node = 1 },
    },
    .ports =
    {
        .arduinoUartPeripheral = { .port = ARDUINO_API_PORT_UART, .node = WILDCARD_NODE_ID },
    },

    .externalNodes =
    {
        .nordicProcessor =  { .port = ARDUINO_API_PORT_UART, .node = RVR_API_NODE_NORDIC },
        .stProcessor =      { .port = ARDUINO_API_PORT_UART, .node = RVR_API_NODE_ST },
    },
};

// API routing table for Arduino
static apiRoute_t apiRoutes[] =
{
    { API_ROUTE_TYPE_DIRECT,    .address = &arduinoApiAddresses.nodes.arduinoProcessor,         .channel = NULL },
    { API_ROUTE_TYPE_DIRECT,    .address = &arduinoApiAddresses.ports.arduinoUartPeripheral,    .channel = &uartChannel},
};

static HardwareSerial* serialForAPI;

// Buffer for the UART receive
static uint8_t uartRXBuffer[MAX_UART_RX_BUFFER_COUNT] = {0};

///////////////////////////////////////////////////////////////////////////////
//  Public Function Implementations
///////////////////////////////////////////////////////////////////////////////

void initUartApi(const HardwareSerial* serial)
{

    apiInit_t apiInit =
    {
        .packetRoutes = apiRoutes,
        .numberOfRoutes = sizeof(apiRoutes) / sizeof(*apiRoutes),
        .localApiAddress = &arduinoApiAddresses.nodes.arduinoProcessor,
        .activityHandler = NULL,
        .restrictedStatusHandler = NULL,
        .responseBuffer = apiResponseDataBuffer,
        .responseBufferSize = sizeof(apiResponseDataBuffer),
    };
    initApi(&apiInit);

    // IO channel setup
    uartChannel.sendBytesToInterface = sendBytesToUart;
    uartChannel.interfaceID = getUniqueChannelEndID();

    // Attach the IO channel to parser
    attachChannelToApi(&uartChannel, &uartChannelApiParser);

    serialForAPI = serial;
    serialForAPI->begin(115200);
}

void serviceUartApi(void)
{
    size_t uartRXBufferRead = 0;
    while((serialForAPI->available() > 0) && (uartRXBufferRead < sizeof(uartRXBuffer)))
    {
        uartRXBuffer[uartRXBufferRead] = serialForAPI->read();
        uartRXBufferRead++;
    }

    if(uartRXBufferRead > 0)
    {
        sendBytesToConsumer(&uartChannel, uartRXBuffer, uartRXBufferRead);
    }
}

bool sendApiCommandToNode(uint8_t nodeId, apiPacket_t *command, apiReponseHandler_t apiResponseCallbackHandler)
{
    bool rc = false;

    if(nodeId == RVR_API_NODE_NORDIC)
    {
        rc = true;
        sendApiCommand(command, &arduinoApiAddresses.externalNodes.nordicProcessor, apiResponseCallbackHandler);
    }
    else if(nodeId = RVR_API_NODE_ST)
    {
        rc = true;
        sendApiCommand(command, &arduinoApiAddresses.externalNodes.stProcessor, apiResponseCallbackHandler);
    }

    return rc;
}

///////////////////////////////////////////////////////////////////////////////
//  Private Function Implementations
///////////////////////////////////////////////////////////////////////////////

static void sendBytesToUart(const ioChannel_t *channel, const uint8_t *data, size_t count)
{
    serialForAPI->write(data, count);
}