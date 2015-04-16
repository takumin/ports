# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	powerline-status
PORTVERSION=	2.1
CATEGORIES=	sysutils devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Powerline is a statusline plugin

LICENSE=	MIT

RUN_DEPENDS=	socat:${PORTSDIR}/net/socat \
		${PYTHON_PKGNAMEPREFIX}psutil>0:${PORTSDIR}/sysutils/py-psutil \
		${PYTHON_PKGNAMEPREFIX}pygit2>0:${PORTSDIR}/devel/py-pygit2 \
		${PYTHON_PKGNAMEPREFIX}pyuv>0:${PORTSDIR}/devel/py-pyuv \
		${PYTHON_PKGNAMEPREFIX}i3-py>0:${PORTSDIR}/devel/py-i3-py

USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		BZR HG
#OPTIONS_GROUP=		FONT
#OPTIONS_GROUP_FONT=	ANONYMICE DEJAVU DROID INCONSOLATA INCONSOLATA_DZ \
#			INCONSOLATA_G LITERATION MESLO SAUCE TERMINESS \
#			UBUNTU MONOFUR FURA

BZR_DESC=		Install mercurial
HG_DESC=		Install bazaar

ANONYMICE_DESC=		Install "Anonymice Powerline" Font
DEJAVU_DESC=		Install "DejaVu Sans Mono for Powerline" Font
DROID_DESC=		Install "Droid Sans Mono for Powerline" Font
INCONSOLATA_DESC=	Install "Inconsolata for Powerline" Font
INCONSOLATA_DZ_DESC=	Install "Inconsolata-dz for Powerline" Font
INCONSOLATA_G_DESC=	Install "Inconsolata-g for Powerline" Font
LITERATION_DESC=	Install "Literation Mono Powerline" Font
MESLO_DESC=		Install "Meslo for Powerline" Font
SAUCE_DESC=		Install "Sauce Code Powerline" Font
TERMINESS_DESC=		Install "Terminess Powerline" Font
UBUNTU_DESC=		Install "Ubuntu Mono derivative Powerline" Font
MONOFUR_DESC=		Install "Monofur for Powerline" Font
FURA_DESC=		Install "Fura Powerline" Font

BZR_RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bzr
HG_RUN_DEPENDS=		hg:${PORTSDIR}/devel/mercurial

.include <bsd.port.mk>
