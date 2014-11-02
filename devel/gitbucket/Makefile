# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	gitbucket
PORTVERSION=	2.4.1
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/takezoe/gitbucket/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.war
EXTRACT_ONLY=

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	GitBucket is the easily installable Github clone written with Scala.

USE_JAVA=	yes
JAVA_VERSION=	1.7+

NO_BUILD=	yes

USE_RC_SUBR=	gitbucket

GITBUCKET_HOME?=	${PREFIX}/gitbucket
GITBUCKET_USER?=	gitbucket
GITBUCKET_GROUP?=	gitbucket

.if ${GITBUECKET_USER} == "gitbucket"
USERS=	gitbucket
.endif
.if ${GITBUECKET_GROUP} == "gitbucket"
GROUPS=	gitbucket
.endif

SUB_LIST+=	GITBUCKET_HOME=${GITBUCKET_HOME} \
		GITBUCKET_USER=${GITBUCKET_USER} \
		GITBUCKET_GROUP=${GITBUCKET_GROUP} \
		JAVA_HOME=${JAVA_HOME}
PLIST_SUB+=	GITBUECKET_USER=${GITBUECKET_USER} \
		GITBUECKET_GROUP=${GITBUECKET_GROUP}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${GITBUECKET_HOME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
