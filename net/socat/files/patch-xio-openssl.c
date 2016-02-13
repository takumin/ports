--- xio-openssl.c.orig	2016-02-13 07:33:21 UTC
+++ xio-openssl.c
@@ -110,7 +110,7 @@ const struct optdesc opt_openssl_cafile 
 const struct optdesc opt_openssl_capath      = { "openssl-capath",     "capath", OPT_OPENSSL_CAPATH,      GROUP_OPENSSL, PH_SPEC, TYPE_FILENAME, OFUNC_SPEC };
 const struct optdesc opt_openssl_egd         = { "openssl-egd",        "egd",    OPT_OPENSSL_EGD,         GROUP_OPENSSL, PH_SPEC, TYPE_FILENAME, OFUNC_SPEC };
 const struct optdesc opt_openssl_pseudo      = { "openssl-pseudo",     "pseudo", OPT_OPENSSL_PSEUDO,      GROUP_OPENSSL, PH_SPEC, TYPE_BOOL,     OFUNC_SPEC };
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000L) && !defined(OPENSSL_NO_COMP)
 const struct optdesc opt_openssl_compress    = { "openssl-compress",   "compress", OPT_OPENSSL_COMPRESS,  GROUP_OPENSSL, PH_SPEC, TYPE_STRING,   OFUNC_SPEC };
 #endif
 #if WITH_FIPS
@@ -147,7 +147,7 @@ int xio_reset_fips_mode(void) {
 static void openssl_conn_loginfo(SSL *ssl) {
    Notice1("SSL connection using %s", SSL_get_cipher(ssl));
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000L) && !defined(OPENSSL_NO_COMP)
    {
       const COMP_METHOD *comp, *expansion;
 
@@ -651,7 +651,7 @@ int _xioopen_openssl_listen(struct singl
 #endif /* WITH_LISTEN */
 
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000L) && !defined(OPENSSL_NO_COMP)
 /* In OpenSSL 0.9.7 compression methods could be added using
  * SSL_COMP_add_compression_method(3), but the implemntation is not compatible
  * with the standard (RFC3749).
@@ -723,7 +723,7 @@ int
    char *opt_cafile = NULL;	/* certificate authority file */
    char *opt_capath = NULL;	/* certificate authority directory */
    char *opt_egd = NULL;	/* entropy gathering daemon socket path */
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000L) && !defined(OPENSSL_NO_COMP)
    char *opt_compress = NULL;	/* compression method */
 #endif
    bool opt_pseudo = false;	/* use pseudo entropy if nothing else */
@@ -743,7 +743,7 @@ int
    retropt_string(opts, OPT_OPENSSL_DHPARAM, &opt_dhparam);
    retropt_string(opts, OPT_OPENSSL_EGD, &opt_egd);
    retropt_bool(opts,OPT_OPENSSL_PSEUDO, &opt_pseudo);
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000L) && !defined(OPENSSL_NO_COMP)
    retropt_string(opts, OPT_OPENSSL_COMPRESS, &opt_compress);
 #endif
 #if WITH_FIPS
@@ -991,7 +991,7 @@ int
    }
 #endif /* !defined(EC_KEY) */
 
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000L) && !defined(OPENSSL_NO_COMP)
    if (opt_compress) {
       int result;
       result = openssl_setup_compression(*ctx, opt_compress);
