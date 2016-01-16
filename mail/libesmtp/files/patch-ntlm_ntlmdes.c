--- ntlm/ntlmdes.c.orig	2016-01-16 12:55:37 UTC
+++ ntlm/ntlmdes.c
@@ -30,10 +30,10 @@
 #include "ntlm.h"
 
 static void
-lm_deshash (void *result, const_des_cblock *iv, const void *secret)
+lm_deshash (void *result, const_DES_cblock *iv, const void *secret)
 {
-  des_cblock key;
-  des_key_schedule ks;
+  DES_cblock key;
+  DES_key_schedule ks;
   unsigned char key_56[8];
   size_t len;
 
@@ -55,9 +55,9 @@ lm_deshash (void *result, const_des_cblo
   key[6] = (key_56[5] << 2) | (key_56[6] >> 6);
   key[7] = (key_56[6] << 1);
 
-  des_set_odd_parity (&key);
-  des_set_key (&key, ks);
-  des_ecb_encrypt (iv, result, ks, DES_ENCRYPT);
+  DES_set_odd_parity (&key);
+  DES_set_key (&key, ks);
+  DES_ecb_encrypt (iv, result, ks, DES_ENCRYPT);
 
   /* paranoia */
   memset (key, 0, sizeof key);
@@ -85,7 +85,7 @@ lm_uccpy (char *dst, size_t dstlen, cons
 void
 lm_hash_password (unsigned char *hash, const char *pass)
 {
-  static const_des_cblock iv = { 0x4B, 0x47, 0x53, 0x21,
+  static const_DES_cblock iv = { 0x4B, 0x47, 0x53, 0x21,
                                  0x40, 0x23, 0x24, 0x25 };
   char lmpass[14];
 
@@ -137,7 +137,7 @@ ntlm_responses (unsigned char *lm_resp, 
 		const unsigned char *challenge, const char *secret)
 {
   unsigned char hash[21];
-  des_cblock nonce;
+  DES_cblock nonce;
 
   memcpy (&nonce, challenge, sizeof nonce);
 
