--
-- PostgreSQL database dump
--

-- Dumped from database version 9.1.4
-- Dumped by pg_dump version 9.1.4
-- Started on 2012-07-30 17:31:53 CEST

SET statement_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

SET search_path = public, pg_catalog;

--
-- TOC entry 2507 (class 0 OID 0)
-- Dependencies: 184
-- Name: T_ADDON_ADO_ADO_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ADDON_ADO_ADO_ID_seq"', 1, false);


--
-- TOC entry 2508 (class 0 OID 0)
-- Dependencies: 208
-- Name: T_ALERT_ACKNOWLEDGE_ACK_ACK_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ALERT_ACKNOWLEDGE_ACK_ACK_ID_seq"', 1, false);


--
-- TOC entry 2509 (class 0 OID 0)
-- Dependencies: 165
-- Name: T_ALERT_ALE_ALE_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ALERT_ALE_ALE_ID_seq"', 1, false);


--
-- TOC entry 2510 (class 0 OID 0)
-- Dependencies: 199
-- Name: T_ALERT_CRITERIA_ACR_ACR_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ALERT_CRITERIA_ACR_ACR_ID_seq"', 1, false);


--
-- TOC entry 2511 (class 0 OID 0)
-- Dependencies: 161
-- Name: T_ALERT_PARAM_APA_APA_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ALERT_PARAM_APA_APA_ID_seq"', 1, false);


--
-- TOC entry 2512 (class 0 OID 0)
-- Dependencies: 201
-- Name: T_ALERT_TRACKING_ATR_ATR_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ALERT_TRACKING_ATR_ATR_ID_seq"', 1, false);


--
-- TOC entry 2513 (class 0 OID 0)
-- Dependencies: 163
-- Name: T_ALERT_TYPE_ATY_ATY_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ALERT_TYPE_ATY_ATY_ID_seq"', 1, false);


--
-- TOC entry 2514 (class 0 OID 0)
-- Dependencies: 212
-- Name: T_ASSET_AST_AST_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ASSET_AST_AST_ID_seq"', 1, false);


--
-- TOC entry 2515 (class 0 OID 0)
-- Dependencies: 230
-- Name: T_INFORMATION_HISTORICAL_VALUE_IHV_IHV_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_INFORMATION_HISTORICAL_VALUE_IHV_IHV_ID_seq"', 1, false);


--
-- TOC entry 2516 (class 0 OID 0)
-- Dependencies: 188
-- Name: T_INFORMATION_UNIT_TYPE_UTY_IUT_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_INFORMATION_UNIT_TYPE_UTY_IUT_ID_seq"', 1, false);


--
-- TOC entry 2517 (class 0 OID 0)
-- Dependencies: 190
-- Name: T_INFORMATION_UNIT_UNT_INU_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_INFORMATION_UNIT_UNT_INU_ID_seq"', 1, false);


--
-- TOC entry 2518 (class 0 OID 0)
-- Dependencies: 216
-- Name: T_INFORMATION_VALUE_IVA_IVA_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_INFORMATION_VALUE_IVA_IVA_ID_seq"', 1, false);


--
-- TOC entry 2519 (class 0 OID 0)
-- Dependencies: 168
-- Name: T_MEDIA_MED_MED_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_MEDIA_MED_MED_ID_seq"', 1, false);


--
-- TOC entry 2520 (class 0 OID 0)
-- Dependencies: 176
-- Name: T_MEDIA_VALUE_MEV_MEV_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_MEDIA_VALUE_MEV_MEV_ID_seq"', 1, false);


--
-- TOC entry 2521 (class 0 OID 0)
-- Dependencies: 232
-- Name: T_OPTION_OPT_OPT_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_OPTION_OPT_OPT_ID_seq"', 1, false);


--
-- TOC entry 2522 (class 0 OID 0)
-- Dependencies: 223
-- Name: T_ORGANIZATION_FIELD_OFI_OFI_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ORGANIZATION_FIELD_OFI_OFI_ID_seq"', 1, false);


--
-- TOC entry 2523 (class 0 OID 0)
-- Dependencies: 197
-- Name: T_ORGANIZATION_ORG_ORG_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ORGANIZATION_ORG_ORG_ID_seq"', 1, false);


--
-- TOC entry 2524 (class 0 OID 0)
-- Dependencies: 195
-- Name: T_ORGANIZATION_TYPE_OTY_OTY_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_ORGANIZATION_TYPE_OTY_OTY_ID_seq"', 1, false);


--
-- TOC entry 2525 (class 0 OID 0)
-- Dependencies: 193
-- Name: T_PACK_PCK_PCK_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_PACK_PCK_PCK_ID_seq"', 1, false);


--
-- TOC entry 2526 (class 0 OID 0)
-- Dependencies: 182
-- Name: T_PLUGIN_PLG_PLG_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_PLUGIN_PLG_PLG_ID_seq"', 1, false);


--
-- TOC entry 2527 (class 0 OID 0)
-- Dependencies: 210
-- Name: T_PROBE_PRB_PRB_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_PROBE_PRB_PRB_ID_seq"', 1, false);


--
-- TOC entry 2528 (class 0 OID 0)
-- Dependencies: 204
-- Name: T_SEARCH_PARAMETER_SEP_SEP_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_SEARCH_PARAMETER_SEP_SEP_ID_seq"', 1, false);


--
-- TOC entry 2529 (class 0 OID 0)
-- Dependencies: 178
-- Name: T_SEARCH_TYPE_STY_STY_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_SEARCH_TYPE_STY_STY_ID_seq"', 1, false);


--
-- TOC entry 2530 (class 0 OID 0)
-- Dependencies: 206
-- Name: T_SOURCE_PARAMETER_SRP_SRP_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_SOURCE_PARAMETER_SRP_SRP_ID_seq"', 1, false);


--
-- TOC entry 2531 (class 0 OID 0)
-- Dependencies: 218
-- Name: T_SPACE_SPA_SPA_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_SPACE_SPA_SPA_ID_seq"', 1, false);


--
-- TOC entry 2532 (class 0 OID 0)
-- Dependencies: 214
-- Name: T_SYSLOG_SLO_SLO_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_SYSLOG_SLO_SLO_ID_seq"', 1, false);


--
-- TOC entry 2533 (class 0 OID 0)
-- Dependencies: 180
-- Name: T_USER_ACTION_ACT_UAC_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_USER_ACTION_ACT_UAC_ID_seq"', 1, false);


--
-- TOC entry 2534 (class 0 OID 0)
-- Dependencies: 234
-- Name: T_USER_FIELD_UFI_UFI_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_USER_FIELD_UFI_UFI_ID_seq"', 1, false);


--
-- TOC entry 2535 (class 0 OID 0)
-- Dependencies: 228
-- Name: T_USER_HISTORICAL_ACTION_UHA_UHA_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_USER_HISTORICAL_ACTION_UHA_UHA_ID_seq"', 1, false);


--
-- TOC entry 2536 (class 0 OID 0)
-- Dependencies: 172
-- Name: T_USER_PROFILE_UPR_UPR_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_USER_PROFILE_UPR_UPR_ID_seq"', 1, false);


--
-- TOC entry 2537 (class 0 OID 0)
-- Dependencies: 220
-- Name: T_USER_RIGHT_URI_URI_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_USER_RIGHT_URI_URI_ID_seq"', 1, false);


--
-- TOC entry 2538 (class 0 OID 0)
-- Dependencies: 170
-- Name: T_USER_ROLE_URO_URO_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_USER_ROLE_URO_URO_ID_seq"', 1, false);


--
-- TOC entry 2539 (class 0 OID 0)
-- Dependencies: 174
-- Name: T_USER_USR_USR_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('"T_USER_USR_USR_ID_seq"', 1, true);


--
-- TOC entry 2540 (class 0 OID 0)
-- Dependencies: 239
-- Name: auth_identity_id_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('auth_identity_id_seq', 1, true);


--
-- TOC entry 2541 (class 0 OID 0)
-- Dependencies: 237
-- Name: auth_info_id_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('auth_info_id_seq', 1, true);


--
-- TOC entry 2542 (class 0 OID 0)
-- Dependencies: 241
-- Name: auth_token_id_seq; Type: SEQUENCE SET; Schema: public; Owner: echoes
--

SELECT pg_catalog.setval('auth_token_id_seq', 1, false);


--
-- TOC entry 2471 (class 0 OID 98847)
-- Dependencies: 200
-- Data for Name: T_ALERT_CRITERIA_ACR; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2450 (class 0 OID 98551)
-- Dependencies: 162
-- Data for Name: T_ALERT_PARAM_APA; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2496 (class 0 OID 99246)
-- Dependencies: 243 2450 2471
-- Data for Name: TJ_ACR_APA; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2462 (class 0 OID 98715)
-- Dependencies: 185
-- Data for Name: T_ADDON_ADO; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2475 (class 0 OID 98905)
-- Dependencies: 207
-- Data for Name: T_SOURCE_PARAMETER_SRP; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2500 (class 0 OID 99314)
-- Dependencies: 247 2475 2462
-- Data for Name: TJ_ADO_SRP; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2469 (class 0 OID 98815)
-- Dependencies: 196
-- Data for Name: T_ORGANIZATION_TYPE_OTY; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2468 (class 0 OID 98804)
-- Dependencies: 194
-- Data for Name: T_PACK_PCK; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2470 (class 0 OID 98826)
-- Dependencies: 198 2468 2469
-- Data for Name: T_ORGANIZATION_ORG; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2477 (class 0 OID 98937)
-- Dependencies: 211 2470
-- Data for Name: T_PROBE_PRB; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2478 (class 0 OID 98953)
-- Dependencies: 213 2477
-- Data for Name: T_ASSET_AST; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2461 (class 0 OID 98704)
-- Dependencies: 183
-- Data for Name: T_PLUGIN_PLG; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2504 (class 0 OID 99382)
-- Dependencies: 251 2478 2461
-- Data for Name: TJ_AST_PLG; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2451 (class 0 OID 98562)
-- Dependencies: 164
-- Data for Name: T_ALERT_TYPE_ATY; Type: TABLE DATA; Schema: public; Owner: echoes
--

INSERT INTO "T_ALERT_TYPE_ATY" VALUES (1, 0, 'SMS', NULL);


--
-- TOC entry 2499 (class 0 OID 99297)
-- Dependencies: 246 2471 2451
-- Data for Name: TJ_ATY_ACR; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2484 (class 0 OID 99053)
-- Dependencies: 224
-- Data for Name: T_ORGANIZATION_FIELD_OFI; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2501 (class 0 OID 99331)
-- Dependencies: 248 2469 2484
-- Data for Name: TJ_OFI_OTY; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2490 (class 0 OID 99163)
-- Dependencies: 233
-- Data for Name: T_OPTION_OPT; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2502 (class 0 OID 99348)
-- Dependencies: 249 2468 2490
-- Data for Name: TJ_PCK_OPT; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2474 (class 0 OID 98894)
-- Dependencies: 205
-- Data for Name: T_SEARCH_PARAMETER_SEP; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2459 (class 0 OID 98682)
-- Dependencies: 179
-- Data for Name: T_SEARCH_TYPE_STY; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2497 (class 0 OID 99263)
-- Dependencies: 244 2459 2474
-- Data for Name: TJ_STY_SEP; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2456 (class 0 OID 98629)
-- Dependencies: 173
-- Data for Name: T_USER_PROFILE_UPR; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2455 (class 0 OID 98618)
-- Dependencies: 171
-- Data for Name: T_USER_ROLE_URO; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2457 (class 0 OID 98640)
-- Dependencies: 175 2455 2456
-- Data for Name: T_USER_USR; Type: TABLE DATA; Schema: public; Owner: echoes
--

INSERT INTO "T_USER_USR" VALUES (1, 0, 'Test', 'User', 'test@test.com', 'toto', NULL, NULL, NULL);


--
-- TOC entry 2498 (class 0 OID 99280)
-- Dependencies: 245 2470 2457
-- Data for Name: TJ_USR_ORG; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2491 (class 0 OID 99174)
-- Dependencies: 235
-- Data for Name: T_USER_FIELD_UFI; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2503 (class 0 OID 99365)
-- Dependencies: 250 2457 2491
-- Data for Name: TJ_USR_UFI; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2481 (class 0 OID 99011)
-- Dependencies: 219
-- Data for Name: T_SPACE_SPA; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2482 (class 0 OID 99022)
-- Dependencies: 221
-- Data for Name: T_USER_RIGHT_URI; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2483 (class 0 OID 99031)
-- Dependencies: 222 2481 2456 2482
-- Data for Name: T_ACCESS_CONTROL_LIST_ACL; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2452 (class 0 OID 98573)
-- Dependencies: 166 2451
-- Data for Name: T_ALERT_ALE; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2476 (class 0 OID 98916)
-- Dependencies: 209 2452 2457
-- Data for Name: T_ALERT_ACKNOWLEDGE_ACK; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2454 (class 0 OID 98607)
-- Dependencies: 169
-- Data for Name: T_MEDIA_MED; Type: TABLE DATA; Schema: public; Owner: echoes
--

INSERT INTO "T_MEDIA_MED" VALUES (1, 0, 'sms', NULL);


--
-- TOC entry 2458 (class 0 OID 98661)
-- Dependencies: 177 2454 2457
-- Data for Name: T_MEDIA_VALUE_MEV; Type: TABLE DATA; Schema: public; Owner: echoes
--

INSERT INTO "T_MEDIA_VALUE_MEV" VALUES (1, 0, '0687693700', NULL, 1, 1);


--
-- TOC entry 2472 (class 0 OID 98858)
-- Dependencies: 202 2458 2452
-- Data for Name: T_ALERT_TRACKING_ATR; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2453 (class 0 OID 98587)
-- Dependencies: 167 2452 2450
-- Data for Name: T_ALERT_VALUE_AVA; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2465 (class 0 OID 98759)
-- Dependencies: 189
-- Data for Name: T_INFORMATION_UNIT_TYPE_UTY; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2466 (class 0 OID 98770)
-- Dependencies: 191 2465
-- Data for Name: T_INFORMATION_UNIT_UNT; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2463 (class 0 OID 98724)
-- Dependencies: 186 2461 2462
-- Data for Name: T_SOURCE_SRC; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2464 (class 0 OID 98739)
-- Dependencies: 187 2463 2459
-- Data for Name: T_SEARCH_SEA; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2467 (class 0 OID 98784)
-- Dependencies: 192 2464 2466
-- Data for Name: T_INFORMATION_INF; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2479 (class 0 OID 98969)
-- Dependencies: 215 2477
-- Data for Name: T_SYSLOG_SLO; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2489 (class 0 OID 99137)
-- Dependencies: 231 2478 2479 2467
-- Data for Name: T_INFORMATION_HISTORICAL_VALUE_IHV; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2480 (class 0 OID 98985)
-- Dependencies: 217 2478 2479 2467
-- Data for Name: T_INFORMATION_VALUE_IVA; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2485 (class 0 OID 99062)
-- Dependencies: 225 2484 2470
-- Data for Name: T_ORGANIZATION_VALUE_OVA; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2486 (class 0 OID 99080)
-- Dependencies: 226 2464 2474
-- Data for Name: T_SEARCH_PARAMETER_VALUE_SEV; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2487 (class 0 OID 99098)
-- Dependencies: 227 2475 2463
-- Data for Name: T_SOURCE_PARAMETER_VALUE_SPV; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2460 (class 0 OID 98693)
-- Dependencies: 181
-- Data for Name: T_USER_ACTION_ACT; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2473 (class 0 OID 98877)
-- Dependencies: 203 2457 2457
-- Data for Name: T_USER_HIERARCHY_UHI; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2488 (class 0 OID 99119)
-- Dependencies: 229 2457 2460
-- Data for Name: T_USER_HISTORICAL_ACTION_UHA; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2492 (class 0 OID 99183)
-- Dependencies: 236 2457 2491
-- Data for Name: T_USER_VALUE_UVA; Type: TABLE DATA; Schema: public; Owner: echoes
--



--
-- TOC entry 2493 (class 0 OID 99203)
-- Dependencies: 238 2457
-- Data for Name: auth_info; Type: TABLE DATA; Schema: public; Owner: echoes
--

INSERT INTO auth_info VALUES (1, 0, NULL, '$2y$07$ZlXTRB/iOiq3Z0KzaB/lRenvj2ERc6WjQqRkLkHKO2E.w3uEM0lZa', 'bcrypt', 'nvUL0dBK9oc5p0gN', 1, 0, NULL, '', '', '', NULL, 0);


--
-- TOC entry 2494 (class 0 OID 99219)
-- Dependencies: 240 2493
-- Data for Name: auth_identity; Type: TABLE DATA; Schema: public; Owner: echoes
--

INSERT INTO auth_identity VALUES (1, 0, 1, 'loginname', 'test');


--
-- TOC entry 2495 (class 0 OID 99235)
-- Dependencies: 242 2493
-- Data for Name: auth_token; Type: TABLE DATA; Schema: public; Owner: echoes
--



-- Completed on 2012-07-30 17:31:53 CEST

--
-- PostgreSQL database dump complete
--

