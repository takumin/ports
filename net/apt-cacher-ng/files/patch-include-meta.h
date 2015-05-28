--- include/meta.h.orig 2015-05-05 01:06:24.000000000 +0900
+++ include/meta.h      2015-05-05 01:07:45.000000000 +0900
@@ -27,6 +27,8 @@
 #include <cstdlib>
 #include <errno.h>

+#include <sys/types.h>
+
 #define EXTREME_MEMORY_SAVING false

 typedef std::string mstring;
