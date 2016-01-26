--- src/util.c.orig	2015-03-07 00:34:20 UTC
+++ src/util.c
@@ -985,6 +985,8 @@ ask (char const *format, ...)
   ssize_t r;
   va_list args;
 
+  fflush(stderr); /* Ensure pending errors are written before the question */
+
   va_start (args, format);
   vfprintf (stdout, format, args);
   va_end (args);
