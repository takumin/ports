--- include/meta.h.orig	2015-07-30 21:42:27 UTC
+++ include/meta.h
@@ -27,6 +27,8 @@
 #include <cstdlib>
 #include <errno.h>
 
+#include <sys/types.h>
+
 #define EXTREME_MEMORY_SAVING false
 
 typedef std::string mstring;
