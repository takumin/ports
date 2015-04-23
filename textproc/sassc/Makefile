# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD: head/textproc/sassc/Makefile 360717 2014-07-05 03:23:35Z nivit $

PORTNAME=	sassc
PORTVERSION=	3.1.0
CATEGORIES=	textproc
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wrapper around libsass

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	sass

LIB_DEPENDS+=	libsass.so:${PORTSDIR}/textproc/libsass

USES=		autoreconf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
AUTOMAKE_ARGS+=	--add-missing
CONFIGURE_ENV+=	SASSC_VERSION=${PORTVERSION}

PLIST_FILES=	bin/sassc

.include <bsd.port.mk>
