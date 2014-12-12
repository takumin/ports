# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	fontforge
PORTVERSION=	20141126
CATEGORIES=	print

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	c4cea47
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-2b4e6df

GNOME=		pango
USES+=		gettext gmake iconv libtool
BUILD_DEPENDS+=	git:${PORTSDIR}/devel/git
LIB_DEPENDS+=	libuninameslist.so:${PORTSDIR}/textproc/libuninameslist \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libspiro.so:${PORTSDIR}/graphics/libspiro \
		libfreetype.so:${PORTSDIR}/print/freetype2 \

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LDFLAGS+=	-lutil

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-pyextensio --enable-extra-encodings

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.post.mk>
