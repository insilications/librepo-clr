#ifndef LR_CHECKSUM_H
#define LR_CHECKSUM_H

#ifdef __cplusplus
extern "C" {
#endif

/* NOTE! This enum guarantee to be sorted by "hash quality" */
typedef enum {
    LR_CHECKSUM_UNKNOWN,
    LR_CHECKSUM_MD2,        /*    The most weakest hash */
    LR_CHECKSUM_MD5,        /*  |                       */
    LR_CHECKSUM_SHA,        /*  |                       */
    LR_CHECKSUM_SHA1,       /*  |                       */
    LR_CHECKSUM_SHA224,     /*  |                       */
    LR_CHECKSUM_SHA256,     /*  |                       */
    LR_CHECKSUM_SHA384,     /* \|/                      */
    LR_CHECKSUM_SHA512,     /*    The most secure hash  */
} lr_ChecksumType;

lr_ChecksumType lr_checksum_type(const char *type);
char *lr_checksum_calculate(lr_ChecksumType type, int fd);

/**
 * @return      0 - checksums are same, other - checksums are different
 */
int lr_checksum_check(lr_ChecksumType type, int fd, const char *expected);

#ifdef __cplusplus
}
#endif

#endif
