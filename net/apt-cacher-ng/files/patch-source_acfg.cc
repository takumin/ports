--- source/acfg.cc.orig	2015-12-20 14:54:05 UTC
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
