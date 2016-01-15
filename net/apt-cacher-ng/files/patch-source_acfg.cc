--- source/acfg.cc.orig	2016-01-15 16:13:19 UTC
+++ source/acfg.cc
@@ -180,7 +180,7 @@ tProperty n2pTbl[] =
 		BARF("Invalid proxy specification, aborting...");
 	}
 	return true;
-}, [](bool superUser)
+}, [](bool superUser) -> string
 {
 	if(!superUser && !proxy_info.sUserPass.empty())
 		return string("#");
