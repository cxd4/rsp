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

#define MINIMUM_MESSAGE_PRIORITY    1
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

#define EXTERN_COMMAND_LIST_GBI
/* If this is defined, the RSP never executes graphics tasks.
 * Those will all be sent to the video plugin for simulation processing.
 */
#define EXTERN_COMMAND_LIST_ABI
/* If this is defined, the RSP never executes audio tasks; use audio plugin.
 * Enabling both of these does not guarantee that the RSP will never execute.
 */

#define EXTERN_BOOT_NUS_CIC_6105
/* Many of the ROM images running off of a NUS-CIC-6105 boot chip will have
 * sent an RSP boot microcode.  I don't think simulating this is a brilliant
 * idea since LLE is naturally better especially since this code is almost
 * never executed (just during boot?) and has no real speed gain to this,
 * but until I figure out what zilmar did to fix it on LLE I have no choice.
 *
 * Credit goes to Hacktarux for the original code; I just simplified it.
 */

#define EXTERN_SIMULATE_ALL
/* This will forcefully enable all of the macros enlisted above.  In
 * addition, any SP task type that does not fall under any of those will
 * have unpredictable results, due to relying on external modules or plugins.
 * Mathematically speaking, the most likely possibility is that you will
 * kneel before a flurry of error messages.  All simulation must be external,
 * not internal.  Direct emulation from inside the plugin is reserved for
 * accurate, real emulators that need that directness for speed.
 */

#define FP_CORRECTIONS
/* This control applies zilmar's floating-point control strategy.
 * The FP precision used by the RCP is pretty imprecise, more-so even than
 * what the Microsoft code generation settings will allow us to specify.
 *
 * This will only affect the operation of the VU computational divides.
 */

#define SP_EXECUTE_LOG
/* This is my mechanism to use file output of 32 bits per each SP operation.
 * I use this in conjunction with my EXE to handle debug, but still checking
 * every single frame even with file output turned off is ~1-2 VI/s slower.
 */

#define SLL_NOP_AS_SEMICYCLE
/* This is mostly experimental.  It has nothing to do with cycle counts, just
 * prioritizing the check whether the memory instruction word from IMEM is
 * equal to 00000000 [hex] (NOP) before doing a SPECIAL function jump table.
 */

#define VU_EMULATE_FRACTION_SATURATE_UNDERFLOW
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

#define VU_EMULATE_SCALAR_ACCUMULATOR_READ
/* VSAW is the only RSP instruction that can access the vector accumulator
 * elements directly.  In the original RSP for Ultra64 this was supposed to
 * be called `VSAR` "Vector Accumulator Read (and Write)".  (The 'S' probably
 * means "Scalar", if not "Select" or "Store".)  Current RSP emulators agree
 * that in VSAW, the accumulator is copied over to VR[vd], but there is a new
 * step no emulator supports.  In the original VSAR, that behavior is before
 * VR[vs] is copied to those accumulator elements.  By the time this opcode
 * got renamed to "VSAW", however, the acknowledgement of this ceased to be.
 */

#define SP_HACK_CYCLES_BOSS_GAME_STUDIOS
/* The games "Stunt Racer 64" and "World Driver Championship" use a custom
 * SP graphics media microcode designed by Boss Game Studios.  Timing is
 * quite literally of the essence in these cases, and since we have yet to
 * figure out exactly what that means, this macro is for hacking the timing.
 */

/* Un-defines:  `#undef` means off; `// #undef` means on. */
#undef  EXTERN_COMMAND_LIST_GBI // Not really recommended but user preference
#undef  EXTERN_COMMAND_LIST_ABI // Not really significant but user preference
// #undef  EXTERN_BOOT_NUS_CIC_6105 // HLE hack but currently needed :(
#undef  EXTERN_SIMULATE_ALL // Only needed for debugging task types.
#undef  FP_CORRECTIONS // Slower than the unimplemented lookup method
#undef  SP_EXECUTE_LOG // For debugging only.  Keep it off to free CPU.
// #undef  SLL_NOP_AS_SEMICYCLE // Who cares.  Maybe faster, maybe slower
#undef  VU_EMULATE_FRACTION_SATURATE_UNDERFLOW // For speed, keep it off.
// #undef  VU_EMULATE_SCALAR_ACCUMULATOR_READ // experimental but needs tests
#undef  SP_HACK_CYCLES_BOSS_GAME_STUDIOS // Disable this for a speed-up.

#ifdef  EXTERN_SIMULATE_ALL
#define EXTERN_COMMAND_LIST_GBI
#define EXTERN_COMMAND_LIST_ABI
#define EXTERN_BOOT_NUS_CIC_6105
#endif
