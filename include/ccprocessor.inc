#if defined _ccprocessor_included
 #endinput
#endif
#define _ccprocessor_included

#define STATUS_LENGTH       16
#define TEAM_LENGTH         64
#define PREFIX_LENGTH       64
#define NAME_LENGTH         128
#define MESSAGE_LENGTH      256
#define MAX_LENGTH          512

// See description for: 
// native Action ccp_RebuildMessage(const int[] props, int propsCount, ArrayList params);
#define SENDER_INDEX(%0)    (%0 >> 3)
#define SENDER_TEAM(%0)     ((%0 >> 1) & 0x03)
#define SENDER_ALIVE(%0)    view_as<bool>((%0 & 0x01)) 

/* 
API key:
    The value changes if the API has been changed. 
    This is a measure against users who do not follow the changes and do not understand what is happening.

    ATTENTION: Do not change it yourself if you are not ready for the consequences!
*/

#define API_KEY             22012022

#if !defined CORE
    #define API_OOD         "The plugin module uses an outdated API. You must update it."

    #if defined INCLUDE_PACKAGER
        #include <packager>
    #endif

    #if defined INCLUDE_STORAGE
        #include <storage>
    #endif

    #if defined INCLUDE_JSON
        #include <jansson>
    #endif

    #if defined INCLUDE_JSON && defined INCLUDE_PACKAGER
        #include <ccprocessor/modules/channels/ccp-channels>
    #endif
    
#endif

// Message template parts
enum
{
    BIND_PROTOTYPE = 0,

    BIND_STATUS_CO,
    BIND_STATUS,

    BIND_TEAM_CO,
    BIND_TEAM,

    BIND_PREFIX_CO,
    BIND_PREFIX,

    BIND_NAME_CO,
    BIND_NAME,

    BIND_MSG_CO,
    BIND_MSG,

    BIND_MAX
};

enum Processing
{
    Proc_Continue = 0,
    Proc_Change,
    Proc_Reject,
    Proc_Stop
};

#include "ccprocessor/natives.inc"
#include "ccprocessor/forwards.inc"
#include "ccprocessor/stocks.inc"

public SharedPlugin __pl_ccprocessor= 
{
    name = "ccprocessor",
    file = "ccprocessor.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};
