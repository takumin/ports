# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	redmine
PORTVERSION=	3.2.0
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://www.redmine.org/releases/

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Flexible project management web application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

RUN_DEPENDS=	rubygem-actionpack-action_caching>=0:${PORTSDIR}/devel/rubygem-actionpack-action_caching \
		rubygem-actionpack-xml_parser>=0:${PORTSDIR}/textproc/rubygem-actionpack-xml_parser \
		rubygem-builder>=3.0.4:${PORTSDIR}/devel/rubygem-builder \
		rubygem-bundler>=0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-coderay>=1.1.0:${PORTSDIR}/textproc/rubygem-coderay \
		rubygem-i18n>=0.7.0:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-jquery-rails>=3.1.4:${PORTSDIR}/www/rubygem-jquery-rails \
		rubygem-mime-types>=0:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-net-ldap>=0.12.0:${PORTSDIR}/net/rubygem-net-ldap \
		rubygem-protected_attributes>=0:${PORTSDIR}/devel/rubygem-protected_attributes \
		rubygem-rack-openid>=0:${PORTSDIR}/www/rubygem-rack-openid \
		rubygem-ruby-openid>=2.3.0:${PORTSDIR}/net/rubygem-ruby-openid \
		rubygem-rails>=4.2.5:${PORTSDIR}/www/rubygem-rails4 \
		rubygem-rake>=0:${PORTSDIR}/devel/rubygem-rake \
		rubygem-rbpdf>=0:${PORTSDIR}/print/rubygem-rbpdf \
		rubygem-redcarpet>=3.3.2:${PORTSDIR}/textproc/rubygem-redcarpet \
		rubygem-request_store>=1.0.5:${PORTSDIR}/devel/rubygem-request_store \
		rubygem-rubytree>=0:${PORTSDIR}/devel/rubygem-rubytree

NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes
USES=		cpe

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST=	RUBY_NAME=${RUBY_NAME}

OPTIONS_DEFINE=	MYSQL POSTGRESQL RMAGIC
OPTIONS_DEFAULT=MYSQL RMAGIC THIN
OPTIONS_SINGLE=	WWWSERVER
OPTIONS_SINGLE_WWWSERVER=	THIN PASSENGER
OPTIONS_SUB=	yes
MYSQL_DESC=	Enable MySQL support
POSTGRESQL_DESC=Enable PostgreSQL support
RMAGIC_DESC=	Enable Gantt charts support
PASSENGER_DESC=	Use Apache/Nginx WEB server
THIN_DESC=	Use Thin WEB server
NO_OPTIONS_SORT=yes

MYSQL_RUN_DEPENDS=	rubygem-mysql2>=0:${PORTSDIR}/databases/rubygem-mysql2
PASSENGER_RUN_DEPENDS=	passenger-config:${PORTSDIR}/www/rubygem-passenger
POSTGRESQL_RUN_DEPENDS=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg
RMAGIC_RUN_DEPENDS=	rubygem-rmagick>=2.13.4:${PORTSDIR}/graphics/rubygem-rmagick
THIN_RUN_DEPENDS=	thin:${PORTSDIR}/www/rubygem-thin
THIN_SUB_LIST=		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
THIN_VARS=		USE_RC_SUBR=redmine

.include <bsd.port.mk>
