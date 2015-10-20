# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	ctags
PORTVERSION=	20151017
CATEGORIES=	devel
MASTER_SITES=	GH GHC
PKGNAMEPREFIX=	universal-
PKGNAMESUFFIX=	-devel
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Maintained ctags implementation

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	universal-ctags
GH_PROJECT=	ctags
GH_TAGNAME=	f36c17a5ee1cdd1990ed65a64fe8bbbd0ef76da8

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-readlib --enable-macro-patterns

OPTIONS_DEFINE=		ICONV
OPTIONS_DEFAULT=	ICONV

.include <bsd.port.options.mk>

ICONV_USE=		iconv
ICONV_CONFIGURE_ENABLE=	iconv

post-stage:
	@${RMDIR} ${STAGEDIR}${ETCDIR}/optlib
	@${RMDIR} ${STAGEDIR}${ETCDIR}/preload
	@${RMDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
