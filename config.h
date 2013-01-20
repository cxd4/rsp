/* DLL configurator control head by Iconoclast
 *
 * Macro controls over RSP virtualization behaviors are all switched here.
 * There is no GUI to config such as zilmar's `DllConfig` export because
 * obviously such run-time checks slow down the emulation by checking the
 * configurations per billions of opcode iterations.  Anyone can add a WINGUI
 * config if they like, but I doubt that the performance impact is worth it.
 */

#define _CRT_SECURE_NO_WARNINGS
/* This is only here for people using modern Microsoft compilers.
 * Usually the default warning level complains over "deprecated" CRT methods.
 * It's basically Microsoft's way of saying they're better than everyone.
 */

#undef  MINIMUM_MESSAGE_PRIORITY
/* Many people will have different uses for an RSP emulator.
 * Some people only want to see message boxes for definite RSP LLE errors.
 * Other people are interested in being notified of technical RSP oddities.
 * I have standardized the following priority levels for message boxes:
 *     0:  Any and all message interrupts in this code will notify the user.
 *     1:  Interrupt SP emulation with messages of at least curious cases.
 *     2:  Draw message boxes for N64 situations *probably* unemulated.
 *     3:  Only notify the user of absolute problems in the emulator.
 *     4:  Disable all message printing (less CRT/USER32 lib dependency)
 *         (and also less interference with leisure of full-screen game play)
 * This macro is mainly for maintainability as well as cross-OS portability
 * by calling a custom method which uses the API-specific message print call.
 * See the `void message()` for details on this centralized API invocation.
 */

#undef  EXTERN_COMMAND_LIST_GBI
/* If this is defined, the RSP never executes graphics tasks.
 * Those will all be sent to the video plugin for simulation processing.
 */
#undef  EXTERN_COMMAND_LIST_ABI
/* If this is defined, the RSP never executes audio tasks; use audio plugin.
 * Enabling both of these does not guarantee that the RSP will never execute.
 */

#undef  FP_CORRECTIONS
/* This control applies zilmar's floating-point control strategy.
 * The FP precision used by the RCP is pretty imprecise, more-so even than
 * what the Microsoft code generation settings will allow us to specify.
 *
 * This will only affect the operation of the VU computational divides.
 */

#undef  SP_EXECUTE_LOG
/* This is my mechanism to use file output of 32 bits per each SP operation.
 * I use this in conjunction with my EXE to handle debug, but still checking
 * every single frame even with file output turned off is ~1-2 VI/s slower.
 */

#undef  SLL_NOP_AS_SEMICYCLE
/* This is mostly experimental.  It has nothing to do with cycle counts, just
 * prioritizing the check whether the memory instruction word from IMEM is
 * equal to 00000000 [hex] (NOP) before doing a SPECIAL function jump table.
 */

#undef  VU_EMULATE_FRACTION_SATURATE_UNDERFLOW
/* Since Microsoft's compiler cannot generate the correctly optimized code
 * for this at the moment, I invented this macro control to disable the
 * VMULF security check if both multipliers happen to be equal to -32768.
 *
 * Basically the chance of this happening is extremely small--small enough
 * that Microsoft's CL.EXE should be making the branches ON EQUAL instead of
 * on NOT EQUAL (if true instead of false), taking the branch out of the
 * normal code path only if this underflow exception arises.  Sadly however
 * as of Visual Studio 2010 Microsoft didn't understand that, causing the
 * latency of VMULF to multiply greatly for over 99% of ABI command lists.
 */

#undef  VU_EMULATE_SCALAR_ACCUMULATOR_READ
/* VSAW is the only RSP instruction that can access the vector accumulator
 * elements directly.  In the original RSP for Ultra64 this was supposed to
 * be called `VSAR` "Vector Accumulator Read (and Write)".  (The 'S' probably
 * means "Scalar", if not "Select" or "Store".)  Current RSP emulators agree
 * that in VSAW, the accumulator is copied over to VR[vd], but there is a new
 * step no emulator supports.  In the original VSAR, that behavior is before
 * VR[vs] is copied to those accumulator elements.  By the time this opcode
 * got renamed to "VSAW", however, the acknowledgement of this ceased to be.
 */

/* Choose whether to define, or keep undefined, the above macros. */
#define MINIMUM_MESSAGE_PRIORITY    1 // show most messages of RSP weirdness
// #define EXTERN_COMMAND_LIST_GBI // Not really recommended but user preference
// #define EXTERN_COMMAND_LIST_ABI // Not really significant but user preference
// #define FP_CORRECTIONS // Slower than the unimplemented lookup method
// #define SP_EXECUTE_LOG // For debugging only.  Keep it off to free CPU.
#define SLL_NOP_AS_SEMICYCLE // Who cares.  Maybe faster, maybe slower
#define VU_EMULATE_FRACTION_SATURATE_UNDERFLOW // For speed, keep it off.
#define VU_EMULATE_SCALAR_ACCUMULATOR_READ // experimental but needs tests

#if defined EXTERN_COMMAND_LIST_GBI && defined EXTERN_COMMAND_LIST_ABI
#define L_TITLE "Basic RSP Simulator"
#elif defined EXTERN_COMMAND_LIST_GBI || defined EXTERN_COMMAND_LIST_ABI
#define L_TITLE "Iconoclast's MLE Test"
#else
#define L_TITLE "RSP Interpreter"
#endif
#define L_ABOUT "Thanks for test RDP:  Jabo, ziggy, Gonetz\n"\
                "SP thread examples:  bpoint, zilmar, Ville Linde"
