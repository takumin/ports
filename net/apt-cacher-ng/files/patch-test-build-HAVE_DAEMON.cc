--- test/build/HAVE_DAEMON.cc.orig	2015-09-21 20:05:55 UTC
+++ test/build/HAVE_DAEMON.cc
@@ -1,3 +1,3 @@
 
-#include <unistd.h>
+#include <stdlib.h>
 int main() { return daemon(0, 0); }
