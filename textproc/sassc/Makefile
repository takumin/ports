# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/sassc/Makefile 384225 2015-04-18 12:58:34Z tijl $

PORTNAME=	sassc
PORTVERSION=	3.3.0
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wrapper around libsass

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	sass

LIB_DEPENDS+=	libsass.so:${PORTSDIR}/textproc/libsass

USES=		autoreconf compiler:c++0x libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libsass-include=${LOCALBASE}/include \
		--with-libsass-lib=${LOCALBASE}/lib
PLIST_FILES=	bin/sassc

post-extract:
	@${ECHO_CMD} 'echo ${PORTVERSION}' > ${WRKSRC}/version.sh

post-patch:
	@${REINPLACE_CMD} -e 's@ -ldl@@' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
