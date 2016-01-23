--- sslcls.c.orig	2015-01-24 10:15:22 UTC
+++ sslcls.c
@@ -55,6 +55,7 @@ const SSL_METHOD *sycSSLv2_server_method
 }
 #endif
 
+#if HAVE_SSLv3_client_method
 const SSL_METHOD *sycSSLv3_client_method(void) {
    const SSL_METHOD *result;
    Debug("SSLv3_client_method()");
@@ -62,7 +63,9 @@ const SSL_METHOD *sycSSLv3_client_method
    Debug1("SSLv3_client_method() -> %p", result);
    return result;
 }
+#endif
 
+#if HAVE_SSLv3_server_method
 const SSL_METHOD *sycSSLv3_server_method(void) {
    const SSL_METHOD *result;
    Debug("SSLv3_server_method()");
@@ -70,6 +73,7 @@ const SSL_METHOD *sycSSLv3_server_method
    Debug1("SSLv3_server_method() -> %p", result);
    return result;
 }
+#endif
 
 const SSL_METHOD *sycSSLv23_client_method(void) {
    const SSL_METHOD *result;
@@ -331,14 +335,6 @@ void sycSSL_free(SSL *ssl) {
    return;
 }
 
-int sycRAND_egd(const char *path) {
-   int result;
-   Debug1("RAND_egd(\"%s\")", path);
-   result = RAND_egd(path);
-   Debug1("RAND_egd() -> %d", result);
-   return result;
-}
-
 DH *sycPEM_read_bio_DHparams(BIO *bp, DH **x, pem_password_cb *cb, void *u) {
    DH *result;
    Debug4("PEM_read_bio_DHparams(%p, %p, %p, %p)",
@@ -375,7 +371,7 @@ int sycFIPS_mode_set(int onoff) {
 }
 #endif /* WITH_FIPS */
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000L) && !defined(OPENSSL_NO_COMP)
 const COMP_METHOD *sycSSL_get_current_compression(SSL *ssl) {
    const COMP_METHOD *result;
    Debug1("SSL_get_current_compression(%p)", ssl);
