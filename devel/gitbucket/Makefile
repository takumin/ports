# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	gitbucket
PORTVERSION=	3.10.1
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/gitbucket/gitbucket/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.war
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	GitHub clone powered by Scala

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	1.7+

NO_EXTRACT=	yes
NO_BUILD=	yes

USE_RC_SUBR=	gitbucket

GITBUCKET_HOME?=	${PREFIX}/gitbucket
GITBUCKET_USER?=	gitbucket
GITBUCKET_GROUP?=	gitbucket

.if ${GITBUCKET_USER} == "gitbucket"
UID_FILES=	${FILESDIR}/UIDs
USERS=	gitbucket
.endif
.if ${GITBUCKET_GROUP} == "gitbucket"
GID_FILES=	${FILESDIR}/GIDs
GROUPS=	gitbucket
.endif

SUB_LIST+=	GITBUCKET_HOME=${GITBUCKET_HOME} \
		GITBUCKET_USER=${GITBUCKET_USER} \
		GITBUCKET_GROUP=${GITBUCKET_GROUP} \
		JAVA_HOME=${JAVA_HOME}
PLIST_SUB+=	GITBUCKET_USER=${GITBUCKET_USER} \
		GITBUCKET_GROUP=${GITBUCKET_GROUP}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${GITBUCKET_HOME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
