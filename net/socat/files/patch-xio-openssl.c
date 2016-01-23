--- xio-openssl.c.orig	2016-01-23 08:37:36 UTC
+++ xio-openssl.c
@@ -147,7 +147,7 @@ int xio_reset_fips_mode(void) {
 static void openssl_conn_loginfo(SSL *ssl) {
    Notice1("SSL connection using %s", SSL_get_cipher(ssl));
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000L) && !defined(OPENSSL_NO_COMP)
    {
       const COMP_METHOD *comp, *expansion;
 
