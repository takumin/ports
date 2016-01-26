--- src/pch.c.orig	2016-01-26 14:37:47 UTC
+++ src/pch.c
@@ -91,6 +91,8 @@ static void next_intuit_at (file_offset,
 static void skip_to (file_offset, lin);
 static char get_ed_command_letter (char const *);
 
+extern bool dont_strip_cr;
+
 /* Prepare to look for the next patch in the patch file. */
 
 void
@@ -514,7 +516,10 @@ intuit_diff_type (bool need_header, mode
 		return NO_DIFF;
 	    }
 	}
-	strip_trailing_cr = 2 <= chars_read && buf[chars_read - 2] == '\r';
+	if (dont_strip_cr)
+	  strip_trailing_cr = 0;
+	else
+	  strip_trailing_cr = 2 <= chars_read && buf[chars_read - 2] == '\r';
 	for (s = buf; *s == ' ' || *s == '\t' || *s == 'X'; s++) {
 	    if (*s == '\t')
 		indent = (indent + 8) & ~7;
