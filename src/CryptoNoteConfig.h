// Copyright (c) 2011-2017 The Cryptonote Developers
// Copyright (c) 2017-2018 The Circle Foundation & Conceal Devs
// Copyright (c) 2018-2019 Conceal Network & Conceal Devs
//
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 17588; /* XCR address prefix to replace the old Nib prefix for NibbleClassic(ticker remains NBXC)*/
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW = 10; /* 20 minutes */
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT = 60 * 60 * 2; /* two hours */
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V1 = 360; /* changed for LWMA3 */
const uint64_t CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE = 10; /* 20 minutes */

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW = 30;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V1 = 11; /* changed for LWMA3 */

const uint64_t MONEY_SUPPLY = UINT64_C(21000000000000); /* max supply: 21M (Consensus II) */

const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX = 0;
const size_t   ZAWY_DIFFICULTY_FIX = 1;
const uint8_t  ZAWY_DIFFICULTY_BLOCK_VERSION = 0;

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE = 100000; /* size of block in bytes, after which reward is calculated using block size */
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT = 6;

const uint64_t POINT = UINT64_C(1000); 
const uint64_t COIN = UINT64_C(1000000); /* smallest atomic unit */
const uint64_t MINIMUM_FEE = UINT64_C(10); /* 0.000010 NBXC */
const uint64_t MINIMUM_FEE_V1 = UINT64_C(100); /* 0.000100 NBXC */
const uint64_t MINIMUM_FEE_V2 = UINT64_C(1000); /* 0.001000 NBXC */
const uint64_t MINIMUM_FEE_BANKING = UINT64_C(1000); /* 0.001000 NBXC */
const uint64_t DEFAULT_DUST_THRESHOLD = UINT64_C(10); /* 0.000010 NBXC */  

const uint64_t DIFFICULTY_TARGET = 120; /* two minutes */
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY = 24 * 60 * 60 / DIFFICULTY_TARGET; /* 720 blocks */
const size_t   DIFFICULTY_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; 
const size_t   DIFFICULTY_WINDOW_V1 = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V2 = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V3 = 60; /* changed for LWMA3 */
const size_t   DIFFICULTY_BLOCKS_COUNT = DIFFICULTY_WINDOW_V3 + 1; /* added for LWMA3 */
const size_t   DIFFICULTY_CUT = 60; /* timestamps to cut after sorting */
const size_t   DIFFICULTY_CUT_V1 = DIFFICULTY_CUT;
const size_t   DIFFICULTY_CUT_V2 = DIFFICULTY_CUT;
const size_t   DIFFICULTY_LAG = 15; 
const size_t   DIFFICULTY_LAG_V1 = DIFFICULTY_LAG;
const size_t   DIFFICULTY_LAG_V2 = DIFFICULTY_LAG;
const size_t   MINIMUM_MIXIN = 4;

static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const uint64_t DEPOSIT_MIN_AMOUNT = 1 * COIN; 
const uint32_t DEPOSIT_MIN_TERM = 5040; /* one week */
const uint32_t DEPOSIT_MAX_TERM = 1 * 12 * 21900; /* legacy deposts - one year */
const uint32_t DEPOSIT_MAX_TERM_V1 = 64800 * 20; /* five years */
const uint32_t DEPOSIT_MIN_TERM_V3 = 21900; /* consensus 2019 - one month */
const uint32_t DEPOSIT_MAX_TERM_V3 = 1 * 12 * 21900; /* consensus 2019 - one year */
const uint32_t DEPOSIT_HEIGHT_V3 = 413400; /* consensus 2019 - deposts v3.0 */
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR = 0; /* constant rate */
const uint64_t DEPOSIT_MAX_TOTAL_RATE = 4; /* legacy deposits */

static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const uint64_t MULTIPLIER_FACTOR = 100; /* legacy deposits */
const uint32_t END_MULTIPLIER_BLOCK = 12750; /* legacy deposits */

const size_t   MAX_BLOCK_SIZE_INITIAL = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const size_t   CRYPTONOTE_MAX_TX_SIZE_LIMIT = (CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE / 4) - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE; /* maximum transaction size */
const size_t   CRYPTONOTE_OPTIMIZE_SIZE = 100; /* proportional to CRYPTONOTE_MAX_TX_SIZE_LIMIT */

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME = (60 * 60 * 12); /* 12 hours in seconds */
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); /* 24 hours in seconds */
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL  = 7; /* CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME  = time to forget tx */

const size_t   FUSION_TX_MAX_SIZE = CRYPTONOTE_MAX_TX_SIZE_LIMIT * 2;
const size_t   FUSION_TX_MIN_INPUT_COUNT = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO = 4;

const uint64_t UPGRADE_HEIGHT = 1;
const uint64_t UPGRADE_HEIGHT_V2 = 1;
const uint64_t UPGRADE_HEIGHT_V3 = 2; /* Cryptonight-Fast */
const uint64_t UPGRADE_HEIGHT_V4 = 3; /* MixIn 2 */
const uint64_t UPGRADE_HEIGHT_V5 = 4; /* Deposits 2.0, Investments 1.0 */
const uint64_t UPGRADE_HEIGHT_V6 = 5; /* LWMA3 */
const uint64_t UPGRADE_HEIGHT_V7 = 6; /* Cryptoight Conceal */
const unsigned UPGRADE_VOTING_THRESHOLD = 90; // percent
const size_t   UPGRADE_VOTING_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; 
const size_t   UPGRADE_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; 

static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[] = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[] = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[] = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[] = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[] = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]       = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                       = "miner_conf.json";

} // parameters

const uint64_t START_BLOCK_REWARD = (UINT64_C(5000) * parameters::POINT); // start reward (Consensus I)
const uint64_t FOUNDATION_TRUST = (UINT64_C(2000000) * parameters::COIN); // funds to secure network  (Consensus II)
const uint64_t MAX_BLOCK_REWARD = (UINT64_C(7) * parameters::COIN); // max reward (Consensus I)
const uint64_t REWARD_INCREASE_INTERVAL = (UINT64_C(21900)); // aprox. 1 month (+ 0.25 NBXC increment per month)

const char     CRYPTONOTE_NAME[] = "nibble";
const char     GENESIS_COINBASE_TX_HEX[] = "010a01ff0001c096b102029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101b01f2b54425ed94515d32a47311858653d281b30a64fc5199dcf7bc7097a4c40";
const uint32_t GENESIS_NONCE = 10000;
const uint64_t GENESIS_TIMESTAMP = 1581120000;

const uint8_t  TRANSACTION_VERSION_1 = 1;
const uint8_t  TRANSACTION_VERSION_2 = 2;
const uint8_t  BLOCK_MAJOR_VERSION_1 = 1; // (Consensus I)
const uint8_t  BLOCK_MAJOR_VERSION_2 = 2; // (Consensus II)
const uint8_t  BLOCK_MAJOR_VERSION_3 = 3; // (Consensus III)
const uint8_t  BLOCK_MAJOR_VERSION_4 = 4; // LWMA3
const uint8_t  BLOCK_MAJOR_VERSION_7 = 7; /* Cryptonight Conceal */
const uint8_t  BLOCK_MINOR_VERSION_0 = 0;
const uint8_t  BLOCK_MINOR_VERSION_1 = 1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT = 10000; // by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT = 128; // by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT = 1000;

const int      P2P_DEFAULT_PORT = 15001;
const int      RPC_DEFAULT_PORT = 16001;


/* P2P Network Configuration Section - This defines our current P2P network version
and the minimum version for communication between nodes */
const uint8_t  P2P_CURRENT_VERSION = 1;
const uint8_t  P2P_MINIMUM_VERSION = 1;
const uint8_t  P2P_UPGRADE_WINDOW = 2;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT = 1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT = 5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE = 64 * 1024 * 1024; // 64MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT = 70; // percent
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL = 60; // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE = 50000000; // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT = 5000; // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT = 2000; // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT = 5000; // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[] = "217A25432A462D4A614E645267556B58703273357638792F423F4428472B4B62";

// Seed Nodes
const std::initializer_list<const char*> SEED_NODES  = {
	"167.99.92.163:15001", // Red pill
	"178.128.174.203:15001", // Blue pill
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// Blockchain Checkpoints:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS  = {

	{0, "4e198698eb8c5251bd3d87abea00f1a8daf0db48614f59945bda79e689e08f6b"},
	{1000, "3aa2f284e010a1993831fd19b56a9a6753030d7c3b11ef22ad61629bdd14e092"},
	{10000, "1a07caf79b54c358a8031eb83d9a1e167a071f3c4d146e148aadc070d6067d38"},
	{20000, "f839221f09760de1d011189887548dec9af78ad37b04939d9dcbe619036fede6"},
	{30000, "fafab0a190eae566523704af325b94b8212c4b2278560a0c31b556ff51f09816"},
	{40000, "e5386fcdd5e47eef7c65d678f3751c2125faf25be7d8b72e7989173f95238886"},
	{50000, "5e19cff7a48e0605a16b7eed2c659227ab2499abb56748102806e2909fc6fa85"},
	{60000, "962f992b839b9b6c8ad5656f894037741fa72188facfadfaaf10f5c630c97be2"},
	{70000, "419d0a74aa69eec20cdaf86da2f982bbf74d3b5407b68932ec1771dd4bdf3559"},
	{80000, "b3c21fbe77c8efe4fba0a2ac1fbd6dbe406aac13a29fe5a2a2338760c449c10e"},
	{90000, "a9669d52ad3931b7168e79d370d03648716119cd4f5a466425b9ec76a4928bc0"},
	{100000, "aeeca9cbabfb7335e25754eb70542f700c4970201a41cb72a82f74c23874eb59"},
	{110000, "b1c6d2a0301f5877c9e746bc209621238fbaa7abb39e0dab2997566901fc8d52"},
	{120000, "5aa22486acba71013014f44bb457e93e64ff5cf31fdd1a33dc305758a1bce0bc"},
	{130000, "07a69bdd2709ea8f0cd21867aec294cb8f650209082e629b24c19fb1221ea89f"},
	{140000, "dee50eaa111e23c8b74b366e5a9ef6b640664ab0f61b87a30810cee6b0c3f183"},
	{150000, "6e590e3dc5a8b0444c73b264d5695dde3a08dd836bce1a7a5e6e1eeee3799899"},
	{160000, "7308b7fdf70849434bb3f0400ce0ac7224e492eb5b0a517d6025840f85a8f474"}
	
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
