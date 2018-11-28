#!/usr/bin/env bash
#for tests
if [ -z "${CIRCLE_TAG}" ] && [ "${CIRCLE_BRANCH}" == "ci-improvements" -o "${CIRCLE_BRANCH}" == "develop" ]; then
	cd ../lib-ledger-core-artifacts
	ls -la 
	aws s3 sync ./ s3://ledger-lib-ledger-core/$LIB_VERSION/ --acl public-read && \
	aws s3 ls s3://ledger-lib-ledger-core/$LIB_VERSION;
fi