# Created by: Daisuke Aoyama <aoyama@peach.ne.jp>
# $FreeBSD$

PORTNAME=	istgt
PORTVERSION=	20141125
CATEGORIES=	net
MASTER_SITES=	http://www.peach.ne.jp/archives/istgt/
PKGNAMESUFFIX=	-fix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	iSCSI target for openSUSE/Debian/NetBSD/FreeBSD

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes

PORTDOCS=	${DOCFILES:T}
DOCFILES=	ChangeLog.jp README doc/QUICKSTART doc/QUICKSTART.jp

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	SYMLNKDEV VBOXVD

SYMLNKDEV_DESC=	Allow symbolic link for device file
VBOXVD_DESC=	Build with VBox VD support (no X11 required)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSYMLNKDEV}
CONFIGURE_ARGS+=--enable-symlink-device
.endif

.if ${PORT_OPTIONS:MVBOXVD}
RUN_DEPENDS+=	${LOCALBASE}/lib/virtualbox/VBoxRT.so:${PORTSDIR}/emulators/virtualbox-ose
BUILD_DEPENDS+=	${LOCALBASE}/lib/virtualbox/VBoxRT.so:${PORTSDIR}/emulators/virtualbox-ose
CONFIGURE_ARGS+=--with-vbox=${LOCALBASE}/include \
		--with-vboxlib=${LOCALBASE}/lib/virtualbox
.endif

post-extract:
	@${REINPLACE_CMD} -e '/\/doc\/istgt/d' ${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
