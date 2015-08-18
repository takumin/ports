# Created by: Tomoyuki Sakurai <cherry@trombik.mine.nu>
# $FreeBSD$

PORTNAME=	puppet
PORTVERSION=	4.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.puppetlabs.com/puppet/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Configuration management framework written in Ruby

LICENSE=	APACHE20

BUILD_DEPENDS=	rubygem-facter>=0:${PORTSDIR}/sysutils/rubygem-facter \
		rubygem-hiera>=0:${PORTSDIR}/sysutils/rubygem-hiera
RUN_DEPENDS=	rubygem-facter>=0:${PORTSDIR}/sysutils/rubygem-facter \
		rubygem-ruby-augeas>=0:${PORTSDIR}/textproc/rubygem-ruby-augeas \
		rubygem-hiera>=0:${PORTSDIR}/sysutils/rubygem-hiera

USES=		cpe
CPE_VENDOR=	puppetlabs
CONFLICTS=	puppet-2* puppet-3*
NO_BUILD=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RC_SUBR=	puppet puppetmaster
USERS=		puppet
GROUPS=		puppet
SUB_FILES+=	pkg-message
SUB_LIST=	RUBY=${RUBY}

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

post-patch:
	@${SED} -i '' -e "s|/etc/puppetlabs/puppet|${ETCDIR}|" \
			-e "s|/etc/puppetlabs/code|/var/puppet/code|" \
			-e "s|/opt/puppetlabs/puppet/cache|/var/puppet|" \
			-e "s|/var/run/puppetlabs|/var/run/puppet|" \
			-e "s|/var/log/puppetlabs/puppet|/var/log/puppet|" \
		${WRKSRC}/install.rb \
		${WRKSRC}/lib/puppet/reference/configuration.rb \
		${WRKSRC}/lib/puppet/util/run_mode.rb
	@${SED} -i ''  -e "s|\$$confdir/ssl|\$$vardir/ssl|" \
		${WRKSRC}/lib/puppet/defaults.rb

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb --no-configs --destdir=${STAGEDIR}

post-install:
	@${MKDIR} ${STAGEDIR}/var/puppet
	@${MKDIR} ${STAGEDIR}${ETCDIR}/manifests
	@${MKDIR} ${STAGEDIR}${ETCDIR}/modules
	@${INSTALL_DATA} ${WRKSRC}/conf/auth.conf ${STAGEDIR}${ETCDIR}/auth.conf-dist
	@${INSTALL_DATA} ${WRKSRC}/conf/environment.conf ${STAGEDIR}${ETCDIR}/environment.conf-dist
	@${INSTALL_DATA} ${WRKSRC}/conf/fileserver.conf ${STAGEDIR}${ETCDIR}/fileserver.conf-dist
	@${RUBY} -I ${STAGEDIR}/${RUBY_SITELIBDIR} ${STAGEDIR}${PREFIX}/bin/puppet agent --genconfig \
		--confdir=${ETCDIR} \
		--codedir=/var/puppet/code \
		--vardir=/var/puppet \
		--rundir=/var/run/puppet \
		--logdir=/var/log/puppet \
		> ${STAGEDIR}${ETCDIR}/puppet.conf-dist

.include <bsd.port.post.mk>
