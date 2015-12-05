--- server/dhcpleasequery.c.orig	2015-08-26 19:13:14 UTC
+++ server/dhcpleasequery.c
@@ -33,6 +33,34 @@
  *       DoS'ed by DHCPLEASEQUERY message.
  */
 
+/*
+ * Get the client identifier from the packet.
+ */
+isc_result_t
+get_client_id(struct packet *packet, struct data_string *client_id) {
+	struct option_cache *oc;
+
+	/*
+	 * Verify our client_id structure is empty.
+	 */
+	if ((client_id->data != NULL) || (client_id->len != 0)) {
+		return DHCP_R_INVALIDARG;
+	}
+
+	oc = lookup_option(&dhcpv6_universe, packet->options, D6O_CLIENTID);
+	if (oc == NULL) {
+		return ISC_R_NOTFOUND;
+	}
+
+	if (!evaluate_option_cache(client_id, packet, NULL, NULL,
+				   packet->options, NULL,
+				   &global_scope, oc, MDL)) {
+		return ISC_R_FAILURE;
+	}
+
+	return ISC_R_SUCCESS;
+}
+
 /* 
  * If you query by hardware address or by client ID, then you may have
  * more than one IP address for your query argument. We need to do two
