/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8588
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b9a0be9239ef58630c6b436ac7ed2cf0bc3a028d
 */

print_ipc_cmd(int cmd)

{

#define output_cmd(val) \

if( cmd == val ) { \

    gemu_log(#val); \

    return; \

}



    cmd &= 0xff;



    /* General IPC commands */

    output_cmd( IPC_RMID );

    output_cmd( IPC_SET );

    output_cmd( IPC_STAT );

    output_cmd( IPC_INFO );

    /* msgctl() commands */

    #ifdef __USER_MISC

    output_cmd( MSG_STAT );

    output_cmd( MSG_INFO );

    #endif

    /* shmctl() commands */

    output_cmd( SHM_LOCK );

    output_cmd( SHM_UNLOCK );

    output_cmd( SHM_STAT );

    output_cmd( SHM_INFO );

    /* semctl() commands */

    output_cmd( GETPID );

    output_cmd( GETVAL );

    output_cmd( GETALL );

    output_cmd( GETNCNT );

    output_cmd( GETZCNT );

    output_cmd( SETVAL );

    output_cmd( SETALL );

    output_cmd( SEM_STAT );

    output_cmd( SEM_INFO );

    output_cmd( IPC_RMID );

    output_cmd( IPC_RMID );

    output_cmd( IPC_RMID );

    output_cmd( IPC_RMID );

    output_cmd( IPC_RMID );

    output_cmd( IPC_RMID );

    output_cmd( IPC_RMID );

    output_cmd( IPC_RMID );

    output_cmd( IPC_RMID );



    /* Some value we don't recognize */

    gemu_log("%d",cmd);

}
