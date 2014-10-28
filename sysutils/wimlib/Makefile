# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	wimlib
PORTVERSION=	1.7.2
CATEGORIES=	sysutils devel
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Library to create, extract, and modify Windows Imaging (WIM) files

LICENSE=	GPLv3

USES=		autoreconf gmake libtool pkgconfig iconv
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
#CONFIGURE_ARGS=	--without-libcrypto
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

OPTIONS_DEFINE=	NTFS
OPTIONS_DEFAULT=NTFS
NTFS_DESC=	Enable libntfs-3g

NTFS_CONFIGURE_WITH=	ntfs-3g
NTFS_LIB_DEPENDS=	libntfs-3g.so:${PORTSDIR}/sysutils/fusefs-ntfs
NTFS_CPPFLAGS=		

.include <bsd.port.mk>
