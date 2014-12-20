# Created by: Stephane Legrand
# $FreeBSD$

PORTNAME=	proftpd
PORTVERSION=	20141220
PKGNAMESUFFIX=	-git
CATEGORIES=	ftp

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Highly configurable FTP daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	proftpd
GH_PROJECT=	proftpd
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	f68d7f3

MAKE_JOBS_UNSAFE=	yes

USES+=		gmake libtool
USE_AUTOTOOLS=	autoconf
USE_OPENSSL=	yes
CPPFLAGS+=	-DHAVE_OPENSSL -I${OPENSSLINC}
LIBS+=		-lssl -lcrypto -L${OPENSSLLIB}

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	install_user=`${ID} -u` \
		install_group=`${ID} -g`
CONFIGURE_ARGS=--localstatedir=/var/run/proftpd \
		--with-pkgconfig=libdata/pkgconfig \
		--with-includes=${LOCALBASE}/include \
		--with-libraries=${LOCALBASE}/lib \
		--enable-ctrls \
		--enable-facl \
		--disable-sendfile \
		--with-modules=mod_ctrls_admin:mod_facl:mod_tls

USE_RC_SUBR=	proftpd
PLIST_SUB+=	LOCALSTATEDIR="/var/run/proftpd"

.include <bsd.port.options.mk>

# FreeBSD-SA-11:07.chroot
.if ${OSVERSION} < 800000
CHROOT_TEST !=	${GREP} __FreeBSD_libc_enter_restricted_mode \
	/usr/include/unistd.h > /dev/null || ${ECHO_CMD} error
. if ${CHROOT_TEST} == "error"
BROKEN=__FreeBSD_libc_enter_restricted_mode is not supported
. endif
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-7-src-fsio.c
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-8-src-fsio.c
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|proftpd\.conf |proftpd.conf.sample |g' ${WRKSRC}/Makefile.in

post-configure:
	${REINPLACE_CMD} -e 's: -lnsl::' ${WRKSRC}/Make.rules
	${REINPLACE_CMD} -e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/usr/bin:${PREFIX}/bin:' \
		${WRKSRC}/src/proftpd.8 ${WRKSRC}/utils/ftpshut.8 \
		${WRKSRC}/utils/ftpcount.1

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/proftpd

.include <bsd.port.post.mk>
