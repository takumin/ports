# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/sassc/Makefile 360717 2014-07-05 03:23:35Z nivit $

PORTNAME=	sassc
PORTVERSION=	3.2.1
CATEGORIES=	textproc
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wrapper around libsass

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	sass

LIB_DEPENDS+=	libsass.so:${PORTSDIR}/textproc/libsass

USES=		pathfix autoreconf gmake libtool compiler:c++0x
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libsass-include=${LOCALBASE}/include \
		--with-libsass-lib=${LOCALBASE}/lib
PLIST_FILES=	bin/sassc

post-extract:
	@${ECHO_CMD} 'echo ${PORTVERSION}' > ${WRKSRC}/version.sh

post-patch:
	@${REINPLACE_CMD} -e 's@ -ldl@@' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
