#ifndef CACHEGRAND_WORKER_OP_H
#define CACHEGRAND_WORKER_OP_H

#ifdef __cplusplus
extern "C" {
#endif

#define WORKER_TIMER_LOOP_MS 500l

typedef bool (worker_op_timer_fp_t)(
        long seconds,
        long long nanoseconds);

typedef network_channel_t* (worker_op_network_channel_new_fp_t)();

typedef network_channel_t* (worker_op_network_channel_multi_new_fp_t)(
        int count);

typedef network_channel_t* (worker_op_network_channel_multi_get_fp_t)(
        network_channel_t* channels,
        int index);

typedef void (worker_op_network_channel_free_fp_t)(
    network_channel_t *network_channel);

typedef network_channel_t* (worker_op_network_accept_fp_t)(
        network_channel_t *listener_channel);

typedef bool (worker_op_network_close_fp_t)(
        network_channel_t *channel);

typedef size_t (worker_op_network_receive_fp_t)(
        network_channel_t *channel,
        char* buffer,
        size_t buffer_length);

typedef size_t (worker_op_network_send_fp_t)(
        network_channel_t *channel,
        char* buffer,
        size_t buffer_length);

typedef size_t (worker_op_network_channel_size_fp_t)();

void worker_timer_fiber_entrypoint(
        void *user_data);

void worker_timer_setup(
        worker_context_t* worker_context);

extern worker_op_timer_fp_t* worker_op_timer;
extern worker_op_network_channel_new_fp_t* worker_op_network_channel_new;
extern worker_op_network_channel_multi_new_fp_t* worker_op_network_channel_multi_new;
extern worker_op_network_channel_multi_get_fp_t* worker_op_network_channel_multi_get;
extern worker_op_network_channel_free_fp_t* worker_op_network_channel_free;
extern worker_op_network_accept_fp_t* worker_op_network_accept;
extern worker_op_network_receive_fp_t* worker_op_network_receive;
extern worker_op_network_send_fp_t* worker_op_network_send;
extern worker_op_network_close_fp_t* worker_op_network_close;
extern worker_op_network_channel_size_fp_t* worker_op_network_channel_size;

#ifdef __cplusplus
}
#endif

#endif //CACHEGRAND_WORKER_OP_H
