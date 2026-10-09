/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8203
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b011f61931f0113b29b7cd7e921dd022e0b04834
 */

int json_lexer_flush(JSONLexer *lexer)

{

    return lexer->state == IN_START ? 0 : json_lexer_feed_char(lexer, 0);

}
