--- source/apt-cacher.cc.orig	2016-02-01 18:48:16 UTC
+++ source/apt-cacher.cc
@@ -5,6 +5,7 @@
 #include <stddef.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <cstdbool>
 #include <cstdint>
