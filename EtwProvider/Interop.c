typedef int LPCGUID;
typedef int HANDLE;
typedef int GUID;
typedef unsigned short USHORT;
typedef unsigned char UCHAR;
typedef unsigned long ULONG;
typedef unsigned long long LARGE_INTEGER;
typedef unsigned long long ULONGLONG;
typedef unsigned long long ULONG64;

typedef struct  _TRACE_GUID_REGISTRATION {
    LPCGUID Guid;            // Guid of data block being registered or updated.
    HANDLE RegHandle;        // Guid Registration Handle is returned.
} TRACE_GUID_REGISTRATION, *PTRACE_GUID_REGISTRATION;

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

typedef struct _EVENT_INSTANCE_HEADER {
  USHORT        Size;
  union {
    USHORT FieldTypeFlags;
    struct {
      UCHAR HeaderType;
      UCHAR MarkerFlags;
    };
  };
  union {
    ULONG  Version;
    struct {
      UCHAR  Type;
      UCHAR  Level;
      USHORT Version;
    } Class;
  };
  ULONG         ThreadId;
  ULONG         ProcessId;
  LARGE_INTEGER TimeStamp;
  ULONGLONG     RegHandle;
  ULONG         InstanceId;
  ULONG         ParentInstanceId;
  union {
    struct {
      ULONG ClientContext;
      ULONG Flags;
    };
    struct {
      ULONG KernelTime;
      ULONG UserTime;
    };
    ULONG64 ProcessorTime;
  };
  ULONGLONG     ParentRegHandle;
} EVENT_INSTANCE_HEADER;