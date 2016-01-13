--- test/build/HAVE_DAEMON.cc.orig	2015-12-20 14:54:05 UTC
+++ test/build/HAVE_DAEMON.cc
@@ -1,3 +1,2 @@
-
-#include <unistd.h>
+#include <stdlib.h>
 int main() { return daemon(0, 0); }
