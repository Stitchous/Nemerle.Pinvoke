

typedef struct _EVENT_TRACE_LOGFILE {
  LPTSTR                       LogFileName;
  LPTSTR                       LoggerName;
  LONGLONG                     CurrentTime;
  ULONG                        BuffersRead;
  union {
    ULONG LogFileMode;
    ULONG ProcessTraceMode;
  };
  EVENT_TRACE                  CurrentEvent;
  TRACE_LOGFILE_HEADER         LogfileHeader;
  PEVENT_TRACE_BUFFER_CALLBACK BufferCallback;
  ULONG                        BufferSize;
  ULONG                        Filled;
  ULONG                        EventsLost;
  union {
    PEVENT_CALLBACK        EventCallback;
    PEVENT_RECORD_CALLBACK EventRecordCallback;
  };
  ULONG                        IsKernelTrace;
  PVOID                        Context1;
} EVENT_TRACE_LOGFILE, *PEVENT_TRACE_LOGFILE;


typedef long long LONGLONG;
typedef short wchar_t;
typedef wchar_t * LPTSTR;
typedef unsigned long ULONG;
typedef void * PVOID;
typedef unsigned long long LARGE_INTEGER;
typedef LPTSTR LPWSTR;

typedef unsigned char UCHAR;

typedef unsigned short USHORT;
typedef unsigned long long ULONGLONG;

typedef PVOID PEVENT_TRACE_BUFFER_CALLBACK;
typedef PVOID PEVENT_RECORD_CALLBACK;
typedef PVOID PEVENT_CALLBACK;

typedef struct _GUID
{
	ULONG u1; ULONG u2; ULONG u3; ULONG u4;
} GUID;

typedef struct _GUIDD
{
	ULONG u1; ULONG u2; ULONG u3; ULONG u4;
} TIME_ZONE_INFORMATION;



typedef struct _TRACE_LOGFILE_HEADER
{
  ULONG                 BufferSize;
  ULONG  Version;
  ULONG                 ProviderVersion;
  ULONG                 NumberOfProcessors;
  LARGE_INTEGER         EndTime;
  ULONG                 TimerResolution;
  ULONG                 MaximumFileSize;
  ULONG                 LogFileMode;
  ULONG                 BuffersWritten;
  GUID                  LogInstanceGuid;
  LPWSTR                LoggerName;
  LPWSTR                LogFileName;
  TIME_ZONE_INFORMATION TimeZone;
  LARGE_INTEGER         BootTime;
  LARGE_INTEGER         PerfFreq;
  LARGE_INTEGER         StartTime;
  ULONG                 ReservedFlags;
  ULONG                 BuffersLost;
} TRACE_LOGFILE_HEADER, *PTRACE_LOGFILE_HEADER;

typedef struct _EVENT_TRACE
{
  EVENT_TRACE_HEADER Header;
  ULONG              InstanceId;
  ULONG              ParentInstanceId;
  GUID               ParentGuid;
  PVOID              MofData;
  ULONG              MofLength;
  ETW_BUFFER_CONTEXT BufferContext;
} EVENT_TRACE, *PEVENT_TRACE;

typedef struct _EVENT_TRACE_HEADER  {
    USHORT      Size;
    USHORT      FieldTypeFlags;
    UCHAR		Type;
    UCHAR		Level;               
    USHORT		Version;             
    ULONG       ThreadId;    
    ULONG       ProcessId;   
    LARGE_INTEGER   TimeStamp;   
    GUID        Guid;            
    ULONG		KernelTime;          
    ULONG		UserTime;            
} EVENT_TRACE_HEADER, *PEVENT_TRACE_HEADER;

typedef struct _ETW_BUFFER_CONTEXT
{
    UCHAR   ProcessorNumber;
    UCHAR   Alignment;
    USHORT  LoggerId;
} ETW_BUFFER_CONTEXT, *PETW_BUFFER_CONTEXT;

typedef struct _EVENT_RECORD {
  EVENT_HEADER                     EventHeader;
  ETW_BUFFER_CONTEXT               BufferContext;
  USHORT                           ExtendedDataCount;
  USHORT                           UserDataLength;
  PEVENT_HEADER_EXTENDED_DATA_ITEM ExtendedData;
  PVOID                            UserData;
  PVOID                            UserContext;
} EVENT_RECORD, *PEVENT_RECORD;

typedef struct _EVENT_HEADER {
  USHORT           Size;
  USHORT           HeaderType;
  USHORT           Flags;
  USHORT           EventProperty;
  ULONG            ThreadId;
  ULONG            ProcessId;
  LARGE_INTEGER    TimeStamp;
  GUID             ProviderId;
  EVENT_DESCRIPTOR EventDescriptor;
  ULONG KernelTime;
  ULONG UserTime;
  GUID             ActivityId;
} EVENT_HEADER, *PEVENT_HEADER;

typedef struct _EVENT_HEADER_EXTENDED_DATA_ITEM {
  USHORT    Reserved1;
  USHORT    ExtType;
  USHORT Linkage;
  USHORT    DataSize;
  ULONGLONG DataPtr;
} EVENT_HEADER_EXTENDED_DATA_ITEM, *PEVENT_HEADER_EXTENDED_DATA_ITEM;

typedef struct _EVENT_DESCRIPTOR {
  USHORT    Id;
  UCHAR     Version;
  UCHAR     Channel;
  UCHAR     Level;
  UCHAR     Opcode;
  USHORT    Task;
  LONGLONG Keyword;
} EVENT_DESCRIPTOR, *PEVENT_DESCRIPTOR;

typedef struct _ENABLE_TRACE_PARAMETERS {
    ULONG                    Version;
    ULONG                    EnableProperty;
    ULONG                    ControlFlags;
    GUID                     SourceId;    
    PEVENT_FILTER_DESCRIPTOR EnableFilterDesc;
} ENABLE_TRACE_PARAMETERS, *PENABLE_TRACE_PARAMETERS;

typedef struct _EVENT_FILTER_DESCRIPTOR {
  ULONGLONG Ptr;
  ULONG     Size;
  ULONG     Type;
} EVENT_FILTER_DESCRIPTOR, *PEVENT_FILTER_DESCRIPTOR;

typedef struct _EVENT_FILTER_HEADER {
  USHORT    Id;
  UCHAR     Version;
  UCHAR     Reserved[5];
  ULONGLONG InstanceId;
  ULONG     Size;
  ULONG     NextOffset;
} EVENT_FILTER_HEADER, *PEVENT_FILTER_HEADER;




typedef ULONG (WINAPI * PEVENT_TRACE_BUFFER_CALLBACK)
                (PEVENT_TRACE_LOGFILE Logfile);

//typedef VOID (WINAPI *PEVENT_RECORD_CALLBACK) (PEVENT_RECORD EventRecord);

//typedef VOID (WINAPI *PEVENT_CALLBACK)( PEVENT_TRACE pEvent );