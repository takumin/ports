# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/libsass/Makefile 384225 2015-04-18 12:58:34Z tijl $

PORTNAME=	libsass
PORTVERSION=	3.2.2
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	sass

USES=		autoreconf compiler:c++11-lib libtool pathfix
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PATHFIX_MAKEFILEIN=	Makefile.am

post-extract:
	@${ECHO_CMD} 'echo ${PORTVERSION}' > ${WRKSRC}/version.sh

.include <bsd.port.mk>
