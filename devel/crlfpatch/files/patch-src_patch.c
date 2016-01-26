--- src/patch.c.orig	2016-01-26 14:37:28 UTC
+++ src/patch.c
@@ -80,6 +80,8 @@ static char const *version_control_conte
 static bool remove_empty_files;
 static bool explicit_inname;
 static enum { RO_IGNORE, RO_WARN, RO_FAIL } read_only_behavior = RO_WARN;
+static bool crlf_flag = false;
+bool dont_strip_cr = false;
 
 /* true if -R was specified on command line.  */
 static bool reverse_flag_specified;
@@ -759,6 +761,8 @@ static struct option const longopts[] =
   {"reject-format", required_argument, NULL, CHAR_MAX + 9},
   {"read-only", required_argument, NULL, CHAR_MAX + 10},
   {"follow-symlinks", no_argument, NULL, CHAR_MAX + 11},
+  {"crlf", no_argument, NULL, CHAR_MAX + 9},
+  {"dont-strip-crlf", no_argument, NULL, CHAR_MAX + 10},
   {NULL, no_argument, NULL, 0}
 };
 
@@ -770,6 +774,9 @@ static char const *const option_help[] =
 "  -F LINES  --fuzz LINES  Set the fuzz factor to LINES for inexact matching.",
 "  -l  --ignore-whitespace  Ignore white space changes between patch and input.",
 "",
+"  --crlf                   Ignore newline for matching the line",
+"  --dont-strip-crlf        Don't strip CRLF",
+"",
 "  -c  --context  Interpret the patch as a context difference.",
 "  -e  --ed  Interpret the patch as an ed script.",
 "  -n  --normal  Interpret the patch as a normal difference.",
@@ -1053,6 +1060,12 @@ get_some_switches (void)
 	    case CHAR_MAX + 11:
 		follow_symlinks = true;
 		break;
+	    case CHAR_MAX + 9:
+	      crlf_flag = false;
+	      break;
+	    case CHAR_MAX + 10:
+	      dont_strip_cr = false;
+	      break;
 	    default:
 		usage (stderr, 2);
 	}
@@ -1671,6 +1684,29 @@ spew_output (struct outstate *outstate, 
     return true;
 }
 
+static int
+patch_match_crlf(char *p1, char *p2)
+{
+  int c1, c2;
+
+  while (*p1 && *p2 &&
+	 *p1 != '\n' &&
+	 *p2 != '\n' &&
+	 *p1 != '\r' &&
+	 *p2 != '\r' &&
+	 *p1 == *p2) {
+    p1++;
+    p2++;
+  }
+  c1 = *p1;
+  if (c1 == '\n' || c1 == '\r')
+    c1 = 0;
+  c2 = *p2;
+  if (c2 == '\n' || c2 == '\r')
+    c2 = 0;
+  return c1 == c2;
+}
+
 /* Does the patch pattern match at line base+offset? */
 
 static bool
@@ -1690,9 +1726,15 @@ patch_match (lin base, lin offset, lin p
 			 pch_line_len(pline) ))
 		return false;
 	}
-	else if (size != pch_line_len (pline)
-		 || memcmp (p, pfetch (pline), size) != 0)
+	else if (crlf_flag) {
+	  if (!patch_match_crlf(p, pfetch(pline)))
 	    return false;
+	}
+	else {
+	  if (size != pch_line_len (pline)
+	      || memcmp (p, pfetch (pline), size) != 0)
+	    return false;
+	}
     }
     return true;
 }
