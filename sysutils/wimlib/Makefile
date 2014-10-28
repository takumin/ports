# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	wimlib
PORTVERSION=	1.7.2
CATEGORIES=	sysutils devel
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Library to create, extract, and modify Windows Imaging (WIM) files

LICENSE=	GPLv3

USES=		gmake pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-ntfs-3g \
		--without-libcrypto
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
