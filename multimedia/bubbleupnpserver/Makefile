# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	bubbleupnpserver
PORTVERSION=	0.9.13
CATEGORIES=	multimedia
MASTER_SITES=	http://www.bubblesoftapps.com/bubbleupnpserver/
DISTNAME=	BubbleUPnPServer-distrib

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	UPnP/DLNA Media Server

USES=		zip
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/BubbleUPnPServerLauncher.jar

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/BubbleUPnPServerLauncher.jar ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
