# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	ctags
PORTVERSION=	20170415
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
GH_TAGNAME=	b96b04e698374fe6fdf205f0a856d72e651a292e

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-readlib --enable-macro-patterns

OPTIONS_DEFINE=		ICONV
OPTIONS_DEFAULT=	ICONV

.include <bsd.port.options.mk>

ICONV_USE=		iconv
ICONV_CONFIGURE_ENABLE=	iconv

pre-configure:
	@cd ${WRKSRC} && ./autogen.sh

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/libexec/ctags/drivers/*
	@${RMDIR} ${STAGEDIR}${PREFIX}/libexec/ctags/drivers
	@${RMDIR} ${STAGEDIR}${PREFIX}/libexec/ctags

.include <bsd.port.mk>
