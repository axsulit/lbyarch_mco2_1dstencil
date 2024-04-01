# 1D Stencil Operation in C and x86-64 Assembly

The 1D Stencil Operation is illusrated as:
Y[i] = X[i] + X[i+1] + X[i+2] + X[i+3] + X[i+4] + X[i+5] + X[i+6] <br>

This was implemented in its C and x86-64 kernels.

### Average Execution Times
<table>
    <thead>
        <tr>
            <th colspan=6>Debug</th>
            <th colspan=6>Release</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td colspan=2 style="text-align: center;">2^20</td>
            <td colspan=2 style="text-align: center;">2^24</td>
            <td colspan=2 style="text-align: center;">2^28</td>
            <td colspan=2 style="text-align: center;">2^20</td>
            <td colspan=2 style="text-align: center;">2^24</td>
            <td colspan=2 style="text-align: center;">2^28</td>
        </tr>
        <tr>
            <td style="text-align: center;">C</td>
            <td style="text-align: center;">ASM</td>
            <td style="text-align: center;">C</td>
            <td style="text-align: center;">ASM</td>
            <td style="text-align: center;">C</td>
            <td style="text-align: center;">ASM</td>
            <td style="text-align: center;">C</td>
            <td style="text-align: center;">ASM</td>
            <td style="text-align: center;">C</td>
            <td style="text-align: center;">ASM</td>
            <td style="text-align: center;">C</td>
            <td style="text-align: center;">ASM</td>
        </tr>
        <tr>
            <td style="padding: 0 15px 0 15px">0.025014</td>
            <td style="padding: 0 15px 0 15px">0.002095</td>
            <td style="padding: 0 15px 0 15px">0.380216</td>
            <td style="padding: 0 15px 0 15px">0.032941</td>
            <td style="padding: 0 15px 0 15px">5.729582</td>
            <td style="padding: 0 15px 0 15px">0.516240</td>
            <td style="padding: 0 15px 0 15px">0.007989</td>
            <td style="padding: 0 15px 0 15px">0.002597</td>
            <td style="padding: 0 15px 0 15px">0.092709</td>
            <td style="padding: 0 15px 0 15px">0.036021</td>
            <td style="padding: 0 15px 0 15px">1.440770</td>
            <td style="padding: 0 15px 0 15px">0.568849</td>
        </tr>
    </tbody>
</table>