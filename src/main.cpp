#include <systemc.h>

SC_MODULE(AVR_CPU) {
    sc_in<bool> clock;
    
    void execute() {
        while (true) {
            wait();  // Wait for clock edge
            std::cout << "Executing instruction at time: " << sc_time_stamp() << std::endl;
        }
    }

    SC_CTOR(AVR_CPU) {
        SC_THREAD(execute);
        sensitive << clock.pos(); // Trigger on positive clock edge
    }
};

int sc_main(int argc, char* argv[]) {
    sc_clock clk("clk", 10, SC_NS);  // 10 ns clock period
    AVR_CPU cpu("CPU");
    cpu.clock(clk);

    sc_start(100, SC_NS); // Run simulation for 100 ns

    return 0;
}
