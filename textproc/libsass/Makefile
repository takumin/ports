# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/libsass/Makefile 360716 2014-07-05 02:58:20Z nivit $

PORTNAME=	libsass
PORTVERSION=	3.1.0
CATEGORIES=	textproc
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	sass

USES=		autoreconf libtool pathfix
USE_LDCONFIG=	yes

PATHFIX_MAKEFILEIN=	Makefile.am
AUTOMAKE_ARGS=	--add-missing
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

pre-configure:
	${REINPLACE_CMD} -e 's@ -lstdc++@@' ${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
