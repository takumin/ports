# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	wimlib
PORTVERSION=	1.8.3
CATEGORIES=	sysutils devel
MASTER_SITES=	http://wimlib.net/downloads/

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Library to create, extract, and modify Windows Imaging (WIM) files

LICENSE=	GPLv3

USES=		gmake iconv libtool pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	FUSE NTFS_3G OPENSSL
OPTIONS_DEFAULT=FUSE NTFS_3G OPENSSL

FUSE_CONFIGURE_WITH=	fuse
NTFS_3G_LIB_DEPENDS=	libfuse.so:${PORTSDIR}/sysutils/fusefs-libs
NTFS_3G_CONFIGURE_WITH=	ntfs-3g
NTFS_3G_LIB_DEPENDS=	libntfs-3g.so:${PORTSDIR}/sysutils/fusefs-ntfs
OPENSSL_CONFIGURE_WITH=	libcrypto
OPENSSL_USE=		openssl=yes

.include <bsd.port.mk>
