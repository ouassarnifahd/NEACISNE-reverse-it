library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- Test Bench : Mise en forme TTL --

architecture behavioral of m_e_form_tb is

component m_e_form_tb is
    port ( clk : in STD_LOGIC;
           TTL : in STD_LOGIC;
           TTL_mef : out STD_LOGIC);
end component m_e_form_tb;

signal clk : STD_LOGIC :='0';
signal TTL : STD_LOGIC :='0';

signal TTL_mef : STD_LOGIC;

begin
    -- device under test --
    dut : m_e_form_tb PORT MAP(clk => clk, TTL => TTL, TTL_mef => TTL_mef);

p1 : process -- Horloge 100 MHz / 10ns --
begin
    clk <= '0';
    wait for 5 ns;
    clk <= '1';
    wait for 5 ns;
end process;

p2 : process -- TTL signal --
begin
    TTL <= '0';
    wait for 55 ns;
    TTL <= '1';
    wait for 55 ns;
end process;

end behavioral;
