# $FreeBSD: head/sysutils/rubygem-librarian-puppet/Makefile 359196 2014-06-25 08:04:23Z robak $

PORTNAME=	librarian-puppet
PORTVERSION=	2.2.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Tool for management and bundling Puppet modules

LICENSE=	MIT

RUN_DEPENDS=	rubygem-librarianp>=0.6.3:${PORTSDIR}/devel/rubygem-librarianp \
		rubygem-puppet_forge>=1.0:${PORTSDIR}/devel/rubygem-puppet_forge \
		rubygem-rsync>=0:${PORTSDIR}/devel/rubygem-rsync \
		ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss \
		git>=0:${PORTSDIR}/devel/git

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/librarian-puppet

.include <bsd.port.mk>
