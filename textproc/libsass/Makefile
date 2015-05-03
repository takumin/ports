# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/libsass/Makefile 360716 2014-07-05 02:58:20Z nivit $

PORTNAME=	libsass
PORTVERSION=	3.2.2
CATEGORIES=	textproc
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	sass

USES=		pathfix autoreconf libtool gmake compiler:c++11-lib
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-extract:
	@${ECHO_CMD} 'echo ${PORTVERSION}' > ${WRKSRC}/version.sh

.include <bsd.port.mk>
