--- server/dhcpv6.c.orig	2015-12-17 01:06:15 UTC
+++ server/dhcpv6.c
@@ -392,34 +392,6 @@ generate_new_server_duid(void) {
 }
 
 /*
- * Get the client identifier from the packet.
- */
-isc_result_t
-get_client_id(struct packet *packet, struct data_string *client_id) {
-	struct option_cache *oc;
-
-	/*
-	 * Verify our client_id structure is empty.
-	 */
-	if ((client_id->data != NULL) || (client_id->len != 0)) {
-		return DHCP_R_INVALIDARG;
-	}
-
-	oc = lookup_option(&dhcpv6_universe, packet->options, D6O_CLIENTID);
-	if (oc == NULL) {
-		return ISC_R_NOTFOUND;
-	}
-
-	if (!evaluate_option_cache(client_id, packet, NULL, NULL,
-				   packet->options, NULL,
-				   &global_scope, oc, MDL)) {
-		return ISC_R_FAILURE;
-	}
-
-	return ISC_R_SUCCESS;
-}
-
-/*
  * Message validation, defined in RFC 3315, sections 15.2, 15.5, 15.7:
  *
  *    Servers MUST discard any Solicit messages that do not include a
