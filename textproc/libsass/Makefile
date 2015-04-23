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

USES=		autoreconf gmake libtool compiler:c++0x
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
