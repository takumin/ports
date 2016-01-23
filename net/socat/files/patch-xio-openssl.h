--- xio-openssl.h.orig	2015-01-24 10:15:22 UTC
+++ xio-openssl.h
@@ -23,7 +23,7 @@ extern const struct optdesc opt_openssl_
 extern const struct optdesc opt_openssl_capath;
 extern const struct optdesc opt_openssl_egd;
 extern const struct optdesc opt_openssl_pseudo;
-#if OPENSSL_VERSION_NUMBER >= 0x00908000L
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000L) && !defined(OPENSSL_NO_COMP)
 extern const struct optdesc opt_openssl_compress;
 #endif
 #if WITH_FIPS
