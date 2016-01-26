# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	patch
PORTVERSION=	2.7.5
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMESUFFIX=	crlf

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	GNU patch utility (CRLF patch)

LICENSE=	GPLv3

USES=		cpe charsetfix gmake tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=crlf --disable-silent-rules
CPE_VENDOR=	gnu

PLIST_FILES=	bin/crlfpatch man/man1/crlfpatch.1.gz

.include <bsd.port.mk>
